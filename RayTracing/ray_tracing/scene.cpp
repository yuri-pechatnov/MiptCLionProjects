//
// Created by ura on 13.04.16.
//

#include "scene.h"
#include "utils.h"
#include "light_source.h"
#include "utils.h"
#include "thread_pool.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <thread>

namespace ImGen {


    Scene &Scene::add(Primitive *fig) {
        figures.push_back(fig);
        return *this;
    }

    Scene &Scene::addLightSource(LightSourceCRef lightSource) {
        lightSources.push_back(lightSource);
        return *this;
    }

    Scene &Scene::setScreen(ScreenCRef screen_) {
        screen = screen_;
        return *this;
    }

    Screen Scene::getScreen() {
        return screen;
    }

    Scene &Scene::setSpectator(PointCRef spectator_) {
        spectator = spectator_;
        return *this;
    }

    PARIntersection Scene::findNearestObstacle(const Ray &ray, double upperLimit) {
        return figuresKDTree.findNearestObstacle(ray, upperLimit);
        /*PARIntersection ans(Color::nan(), Point(), Point(), 1e300);
        for (Primitive *fig : figures) {
            PARIntersectionCRef b = fig->intersectWithRay(ray);
            if (!b.isNan() && b.distance > eps && b.distance < ans.distance && b.distance < upperLimit + eps)
                ans = b;
        }
        return ans;*/
    }

    Color Scene::findColor(RayCRef ray, int prior) {
        PARIntersection intersection = findNearestObstacle(ray);

        if (intersection.isNan())
            return Color::nan();
        Color ans = intersection.getBackgroundComponent();
        Point X = intersection.X;
        if (intersection.isLightSourcesImportant()) {
            for (LightSourceCRef ls : lightSources) {
                Ray toLS = Ray::rayFromAB(X, ls);
                PARIntersection obstacle = findNearestObstacle(toLS, toLS.dirLen);
                if (obstacle.isNan()) {
                    double odistLS = 1.0 / toLS.dirLen;
                    Ray deflLight = intersection.getDeflected(toLS);
                    double koefDefl = (intersection.norm * toLS.dir) * pow3(odistLS), cosGla;
                    if (koefDefl < 0.0) {
                        koefDefl = (intersection.refractive > 0 ? -koefDefl : (double)0.0);
                        cosGla = max(0.0, (ray.dir * toLS.dir) / (ray.dirLen * toLS.dirLen));
                    }
                    else {
                        cosGla = max(0.0, (ray.dir * deflLight.dir) / (ray.dirLen * deflLight.dirLen));
                    }
                    //cerr << cosGla << " " << glareCoefficient * sqr(odistLS) << " " << koefDefl <<  endl;
                    ans = ans + intersection.getDispersiveComponent(ls, koefDefl);
                    ans = ans + intersection.getGlareComponent(ls, cosGla, glareCoefficient * sqr(odistLS));
                }
            }
        }
        if (prior > 0 && intersection.deflective > 0) {
            Ray deflRay = intersection.getDeflected();
            Color deflColor = findColor(deflRay, prior - 1);
            ans = ans + intersection.getDeflectiveComponent(deflColor);
        }
        if (prior > 0 && intersection.refractive > 0 && intersection.refractiveIndex > 0) {
            Ray refrRay = intersection.getRefracted();
            Color refrColor = findColor(refrRay, prior - 1);
            ans = ans + intersection.getRefractiveComponent(refrColor);
        }
        return ans;
    }


    void Scene::multiThreadComputePartOfColors(
            std::function<void(int, int, ColorCRef)> paint, int taskNo, int taskCount) {
        cerr << "task No" << taskNo << " started" << endl;
        for (int i = 0; i < 11; i++) {
            for (int x = 0; x < screen.width; x++) {
                for (int y = 0; y < screen.height; y++) {
                    if (x % taskCount == taskNo && x % 6 + y % 6 == i)
                        paint(x, y, findColor(
                                Ray::rayFromAB(spectator, screen.pixelCoordinatesToPoint(x, y)),
                                deflectionRate
                        ));
                }
            }
        }
        cerr << "task No" << taskNo << " finished" << endl;
    }
    void Scene::multiThreadAntialiasePart(
            std::function<void(int, int, ColorCRef)> paint, std::vector< std::vector <ColorFloat> > &m,
            int level, int taskNo, int taskCount) {
        for (int i = 0; i < 11; i++) {
            for (int x = 1; x + 1 < screen.width; x++) {
                for (int y = 1; y + 1 < screen.height; y++)
                    if (x % 6 + y % 6 == i && x % taskCount == taskNo){
                    int badness = 0;
                    for (int dx : {-1, 1})
                        for (int dy : {-1, 1})
                            badness += (m[x][y] - m[x + dx][y + dy]).norm();
                    if (badness > badnessLimit) {
                        double d = 1.0 / (double)level;
                        ColorFloat sum(0, 0, 0);
                        for (double fx = (double)x - 0.5 + d / 2.0; fx < (double)x + 0.5; fx += d)
                            for (double fy = (double)y - 0.5 + d / 2.0; fy < (double)y + 0.5; fy += d)
                                sum = sum + findColor(
                                        Ray::rayFromAB(spectator, screen.pixelCoordinatesToPoint(fx, fy)),
                                        deflectionRate
                                );
                        paint(x, y, sum * (1.0 / (level * level)));
                    }
                }
            }
        }
    }


    void Scene::computeColors(std::function<void(int, int, ColorCRef)> paint, int threadCount) {
        figuresKDTree.init(figures);
        upto(threadCount, 1);
        downto(threadCount, 4);
        int taskCount = 10;
        ThreadPool pool;
        for (int t = 0; t < taskCount; t++)
            pool.addTask([this, &paint, t, taskCount]() { multiThreadComputePartOfColors(paint, t, taskCount); });
        pool.executeAll(threadCount);
    }

    void Scene::computeColorsAntialiasing(std::function<void(int, int, ColorCRef)> paint, int threadCount, int level) {
        upto(threadCount, 1);
        downto(threadCount, 4);
        std::vector< std::vector <ColorFloat> > m(screen.width, std::vector<ColorFloat> (screen.height, ColorFloat()));
        computeColors([paint, &m](int x, int y, ColorCRef c) { m[x][y] = c; paint(x, y, c); }, threadCount);
        if (level > 1) {
            for (int x = 1; x + 1 < screen.width; x++) {
                for (int y = 1; y + 1 < screen.height; y++) {
                    int badness = 0;
                    for (int dx : {-1, 1})
                        for (int dy : {-1, 1})
                            badness += (m[x][y] - m[x + dx][y + dy]).norm();
                    if (badness > badnessLimit) {
                        paint(x, y, Color(255, 0, 0));
                    }
                }
            }
            int taskCount = 10;
            ThreadPool pool;
            for (int t = 0; t < taskCount; t++)
                pool.addTask([this, &paint, &m, level, t, taskCount]()
                             { multiThreadAntialiasePart(paint, m, level, t, taskCount); });
            pool.executeAll(threadCount);
        }
    }


    void Scene::deleteFigures() {
        for (Primitive *fig : figures)
            delete fig;
        figures.clear();
    }

    SceneLoader Scene::getSceneLoader() {
        return SceneLoader(*this);
    }

    void Scene::setTextureLoader(TextureLoader *loader) {
        textureLoader = loader;
    }

    Scene::Scene(): defaultColor(Color(120, 180, 180)), deflectionRate(1), glareCoefficient(3.0), textureLoader(NULL) {
    }

    Scene::~Scene() {
    }



};