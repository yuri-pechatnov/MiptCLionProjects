//
// Created by ura on 13.04.16.
//

#ifndef RAYTRACING_SCENE_H
#define RAYTRACING_SCENE_H

#include <vector>
#include <string>
#include "fig_primitive.h"
#include "screen.h"
#include "light_source.h"
#include "color.h"
#include "texture_surface.h"
#include "scene_loader.h"

namespace ImGen {

    class Scene {
        friend class SceneLoader;

        std::vector<Primitive *> figures;
        KDTreeOfPrimitives figuresKDTree;
        std::vector<LightSource> lightSources;
        Screen screen;
        Point spectator;
        MetaColor defaultColor;
        int deflectionRate;
        float glareCoefficient;
        static constexpr float badnessLimit = 50;
        std::string sceneName;
        TextureLoader *textureLoader;
        void multiThreadComputePartOfColors(std::function<void(int, int, ColorCRef)>, int taskNo, int taskCount);
        void multiThreadAntialiasePart(
                std::function<void(int, int, ColorCRef)>, std::vector< std::vector <ColorFloat> > &m,
                int level, int taskNo, int taskCount);
    public:
        Scene &add(Primitive *fig);
        Scene &addLightSource(LightSourceCRef lightSource);

        Scene &setScreen(ScreenCRef screen_);
        Screen getScreen();

        Scene &setSpectator(PointCRef spectator_);

        PrimitiveAndRayIntersection findNearestObstacle(RayCRef ray, double upperLimit = 1e300);
        Color findColor(RayCRef ray, int prior = 1);

        void computeColors(std::function<void(int, int, ColorCRef)>, int threadCount = 1);
        void computeColorsAntialiasing(std::function<void(int, int, ColorCRef)>, int threadCount = 1, int level = 1);

        void deleteFigures();

        SceneLoader getSceneLoader();

        void setTextureLoader(TextureLoader *loader);

        Scene();

        ~Scene();
    private:
        template <typename T>
        Scene &operator=(T);
    };

};

#endif //RAYTRACING_SCENE_H
