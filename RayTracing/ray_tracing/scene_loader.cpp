//
// Created by ura on 08.05.16.
//

//
// Created by ura on 13.04.16.
//

#include "scene.h"
#include "utils.h"
#include "light_source.h"
#include "utils.h"
#include "scene_loader.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <ray_tracing/primitives/fig_triangle.h>
#include <algorithm>
#include <vector>
#include <ray_tracing/primitives/fig_sphere.h>
#include <ray_tracing/primitives/fig_polygon.h>
#include <cmath>

namespace ImGen {

    LoadException::LoadException(const std::string &msg) : message(msg) { }

    LoadException::LoadException(const char *spec, ...) {
        std::vector<char> data(256, 0);
        va_list arg;
        va_start(arg, spec);
        vsprintf(data.data(), spec, arg);
        va_end(arg);
        message = data.data();
    }

    const char *LoadException::what() const noexcept { return message.data(); }


    void SceneLoader::load(const char *fileName) {
        scene.deleteFigures();

        FILE *input = fopen(fileName, "rt");
        if (input == NULL)
            throw LoadException("LoadScene: Can't open file \"%s\"\n", fileName);
        char str[1024], a[1024], b[1024];

        {
            fgets(str, 255, input);
            int len;
            b[0] = 0;
            sscanf(str, "%s %s%n", a, b, &len);
            if (strcmp(a, "solid") != 0)
                throw LoadException("Wrong beginning of file: %s", str);
            scene.sceneName = b;
        }

        while (fgets(str, 255, input) != NULL) {
            int len = 0, ret = 0;
            double x, y, z;
            if (sscanf(str, " %s %n", a, &len) == 0 || len == 0)
                continue;
            else if (a[0] == '#')
                continue;
            else if (strcmp(a, "endsolid") == 0)
                break;
            else if (strcmp(a, "facet") == 0)
                loadFacet(input, str);
            else if (strcmp(a, "parallelogram") == 0)
                loadParallelogram(input, str);
            else if (strcmp(a, "plainfacet") == 0)
                loadPlainFacet(input, str);
            else if (strcmp(a, "sphere") == 0)
                loadSphere(input, str);
            else if (strcmp(a, "light_source") == 0) {
                int r, g, b;
                ret = sscanf(str + len, " origin = ( %lf , %lf , %lf ), brightness = ( %d , %d , %d ) ",
                             &x, &y, &z, &r, &g, &b);
                if (ret != 6)
                    throw LoadException("Error in loading light source: %s", str);
                scene.addLightSource(LightSource(Point(x, y, z), r, g, b));
            }
            else if (strcmp(a, "spectator") == 0) {
                ret = sscanf(str + len, " = ( %lf , %lf , %lf )", &x, &y, &z);
                if (ret != 3)
                    throw LoadException("Error in loading spectator: %s", str);
                scene.setSpectator(Point(x, y, z));
            }
            else if (strcmp(a, "look") == 0) {
                Point dir, up, left, s = scene.spectator;
                int w, h;
                if (sscanf(str + len, " dir ( %lf , %lf , %lf ) , up ( %lf , %lf , %lf ) , size ( %d , %d )",
                             &dir.x(), &dir.y(), &dir.z(), &up.x(), &up.y(), &up.z(), &w, &h) != 8)
                    throw LoadException("Error in loading spectator look: %s", str);
                dir = dir.norm();
                up = (up - dir * (dir * up)).norm();
                left = up ^ dir;
                //cerr << s + dir + left + up << endl;
                //cerr << s + dir - left + up << endl;
                //cerr << s + dir + left - up << endl;
                scene.setScreen(Screen(Parallelogram(
                        s + dir + left + up, s + dir - left + up, s + dir + left - up), w, h));
            }
            else if (strcmp(a, "screen") == 0) {
                Point A, W, H;
                int w, h;
                ret = sscanf(str + len, " = ( ( %lf , %lf , %lf ) , ( %lf , %lf , %lf ) , ( %lf , %lf , %lf ) ) "
                        ", ( %d, %d )", &A.x(), &A.y(), &A.z(), &W.x(), &W.y(), &W.z(), &H.x(), &H.y(), &H.z(), &w, &h);
                if (ret != 11)
                    throw LoadException("Error in loading screen: %s", str);
                scene.setScreen(Screen(Parallelogram(A, A + W, A + H), w, h));
            }
            else if (strcmp(a, "deflection_rate") == 0) {
                int rate;
                if (sscanf(str + len, " = %d", &rate) != 1)
                    throw LoadException("Error in loading deflection rate: %s", str);
                scene.deflectionRate = rate;
            }
            else if (strcmp(a, "default_color") == 0) {
                int r, g, b;
                if (sscanf(str + len, " = ( %d , %d , %d )", &r, &g, &b) != 3)
                    throw LoadException("Error in loading default color: %s", str);
                scene.defaultColor = Color(r, g, b);
            }
            else if (strcmp(a, "glare_coefficient") == 0) {
                float coef;
                if (sscanf(str + len, " = %f", &coef) != 1)
                    throw LoadException("Error in loading glare coefficient: %s", str);
                scene.glareCoefficient = coef;
            }
            else
                throw LoadException("Undefined command: %s", str);
        }
    }

    MetaColor SceneLoader::recognizeColor(const char *str) {

        int r, g, b, len;
        size_t pos;
        int ret = sscanf(str, " color = ( %d , %d , %d )%n", &r, &g, &b, &len);
        if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255 || ret != 3)
            throw LoadException("Error in recognising color: %s", str);
        MetaColor ans = Color((unsigned char) r, (unsigned char) g, (unsigned char) b);
        std::string attr = (str + len);
        for (const MetaColor::Field &field : MetaColor::fields)
            if ((pos = attr.find(field.first)) != std::string::npos) {
                if (sscanf(attr.c_str() + pos + field.first.length(), " = %f", &field.second(ans)) != 1)
                    throw LoadException("Error in recognising color attribute \"%s\"", field.first.c_str());
            }
        return ans;
    }

    TextureSurface *SceneLoader::recognizeAndLoadTexture(const char *str) {
        if (scene.textureLoader == NULL)
            throw LoadException("No texture loader set =(");
        int len;
        double wlen, hlen;
        Point AB, AC;
        int ret = sscanf(str, " texture ( ( %lf , %lf , %lf ) , ( %lf , %lf , %lf ) ) ( %lf, %lf ) %n",
                         &AB.x(), &AB.y(), &AB.z(), &AC.x(), &AC.y(), &AC.z(), &wlen, &hlen, &len);
        if (wlen <= 0 || hlen <= 0 || ret != 8)
            throw LoadException("Error in recognising texture: %s", str);
        char fName[512];
        strcpy(fName, str + len);
        for (int i = (int) strlen(fName) - 1; i >= 0 && (fName[i] == '\n' || fName[i] == ' '); i--)
            fName[i] = 0;
        Texture *t = scene.textureLoader->getTexture(fName);
        return new TextureSurface(AB, AC, wlen, hlen, t);
    }

    void SceneLoader::loadFacet(FILE *input, const char *firstString) {
        char str[1024], a[1024];
        std::vector<Point> ps;
        MetaColor color = scene.defaultColor;
        Point normal(0, 0, 0);
        TextureSurface *texture = NULL;
        sscanf(firstString, " facet normal %lf %lf %lf", &normal.x(), &normal.y(), &normal.z());
        while (fgets(str, 255, input) != NULL) {
            int len;
            sscanf(str, " %s%n", a, &len);
            if (strcmp(a, "endfacet") == 0)
                break;
            else if (strcmp(a, "color") == 0)
                color = recognizeColor(str);
            else if (strcmp(a, "texture") == 0)
                texture = recognizeAndLoadTexture(str);
            else if (strcmp(a, "outer") == 0) {
                if (ps.size() != 0)
                    throw LoadException("Points are already set! But: %s", str);
                while (fgets(str, 255, input) != NULL) {
                    int len2;
                    sscanf(str, " %s%n", a, &len2);
                    if (strcmp(a, "endloop") == 0)
                        break;
                    else if (strcmp(a, "vertex") == 0) {
                        Point X;
                        sscanf(str + len2, " %lf %lf %lf ", &X.x(), &X.y(), &X.z());
                        ps.push_back(X);
                    }
                    else
                        throw LoadException("Unrecognised command is found while reading vertexes: %s", str);
                }
                if (ps.size() < 3)
                    throw LoadException("Few points: %s", str);
            }
            else
                throw LoadException("Unrecognised command is found while reading facet: %s", str);
        }
        if ((normal * ((ps[0] >> ps[1]) ^ (ps[0] >> ps[2]))) < 0) {
            std::reverse(ps.begin(), ps.end());
            color = color.invert(-1);
        }
        for (size_t i = 1; i + 1 < ps.size(); i++) {
            scene.add((new Triangle(ps[0], ps[i], ps[i + 1]))->setTextureSurface(texture)->setColor(color));
        }
    }

    void SceneLoader::loadSphere(FILE *input, const char *firstString) {
        char str[1024], a[1024];
        std::vector<Point> ps;
        MetaColor color = scene.defaultColor;
        Point center(0, 0, 0);
        double radius = 1.0;
        while (fgets(str, 255, input) != NULL) {
            int len;
            sscanf(str, " %s%n", a, &len);
            if (strcmp(a, "endsphere") == 0)
                break;
            else if (strcmp(a, "color") == 0)
                color = recognizeColor(str);
            else if (strcmp(a, "radius") == 0) {
                sscanf(str + len, " = %lf", &radius);
                if (radius <= 0)
                    throw LoadException("Radius of sphere is less than zero!: %s", str);
            }
            else if (strcmp(a, "center") == 0) {
                if (sscanf(str + len, " %lf %lf %lf ", &center.x(), &center.y(), &center.z()) != 3)
                    throw LoadException("Error while reading center of the sphere: %s", str);
            }
            else
                throw LoadException("Unrecognised command is found while reading sphere: %s", str);
        }
        scene.add((new Sphere(center, radius))->setColor(color));
    }

    void SceneLoader::loadPlainFacet(FILE *input, const char *firstString) {
        char str[1024], a[1024];
        std::vector<Point> ps;
        MetaColor color = scene.defaultColor;
        Point normal(0, 0, 0), A, X1, Y1;
        TextureSurface *texture = NULL;
        sscanf(firstString, " plainfacet normal %lf %lf %lf", &normal.x(), &normal.y(), &normal.z());
        while (fgets(str, 255, input) != NULL) {
            int len;
            sscanf(str, " %s%n", a, &len);
            if (strcmp(a, "endplainfacet") == 0)
                break;
            else if (strcmp(a, "color") == 0)
                color = recognizeColor(str);
            else if (strcmp(a, "texture") == 0)
                texture = recognizeAndLoadTexture(str);
            else if (strcmp(a, "coordinate_system") == 0) {
                int ret = sscanf(str + len, " = ( ( %lf , %lf , %lf ) , ( %lf , %lf , %lf ) , ( %lf , %lf , %lf ) ) ",
                                 &A.x(), &A.y(), &A.z(), &X1.x(), &X1.y(), &X1.z(), &Y1.x(), &Y1.y(), &Y1.z());
                if (ret != 9)
                    throw LoadException("Error while reading coordinate system: %s", str);
            }
            else if (strcmp(a, "vertexes") == 0) {
                if (ps.size() != 0)
                    throw LoadException("Points are already set! But: %s", str);
                while (fgets(str, 255, input) != NULL) {
                    int len2;
                    sscanf(str, " %s%n", a, &len2);
                    if (strcmp(a, "endvertexes") == 0)
                        break;
                    else if (strcmp(a, "vertex") == 0) {
                        Point X;
                        sscanf(str + len2, " %lf %lf ", &X.x(), &X.y());
                        ps.push_back(X);
                    }
                    else
                        throw LoadException("Unrecognised command is found while reading vertexes: %s", str);
                }
                if (ps.size() < 3)
                    throw LoadException("Few points: %s", str);
            }
            else
                throw LoadException("Unrecognised command is found while reading plain facet: %s", str);
        }
        if ((normal * (X1 ^ Y1)) < 0) {
            std::reverse(ps.begin(), ps.end());
            color = color.invert(-1);
        }
        scene.add((new Polygon(A, X1, Y1, ps))->setTextureSurface(texture)->setColor(color));
    }

    void SceneLoader::loadParallelogram(FILE *input, const char *firstString) {
        char str[1024], a[1024];
        std::vector<Point> ps;
        MetaColor color = scene.defaultColor;
        Point normal(0, 0, 0);
        TextureSurface *texture = NULL;
        sscanf(firstString, " parallelogram normal %lf %lf %lf", &normal.x(), &normal.y(), &normal.z());
        while (fgets(str, 255, input) != NULL) {
            int len;
            sscanf(str, " %s%n", a, &len);
            if (strcmp(a, "endparallelogram") == 0)
                break;
            else if (strcmp(a, "color") == 0)
                color = recognizeColor(str);
            else if (strcmp(a, "texture") == 0)
                texture = recognizeAndLoadTexture(str);
            else if (strcmp(a, "vertexes_abc") == 0) {
                if (ps.size() != 0)
                    throw LoadException("Points are already set! But: %s", str);
                while (fgets(str, 255, input) != NULL) {
                    int len2;
                    sscanf(str, " %s%n", a, &len2);
                    if (strcmp(a, "endvertexes") == 0)
                        break;
                    else if (strcmp(a, "vertex") == 0) {
                        Point X;
                        sscanf(str + len2, " %lf %lf %lf ", &X.x(), &X.y(), &X.z());
                        ps.push_back(X);
                    }
                    else
                        throw LoadException("Unrecognised command is found while reading vertexes: %s", str);
                }
                if (ps.size() != 3)
                    throw LoadException("Inappropriate amount of points (!= 3): %s", str);

            }
            else
                throw LoadException("Unrecognised command is found while reading parallelogram: %s", str);
        }
        if ((normal * ((ps[0] >> ps[1]) ^ (ps[0] >> ps[2]))) < 0) {
            std::reverse(ps.begin(), ps.end());
            color = color.invert(-1);
        }
        scene.add((new Parallelogram(ps[0], ps[1], ps[2]))->setTextureSurface(texture)->setColor(color));
    }

    SceneLoader::SceneLoader(Scene &scene): scene(scene) { }

}