//
// Created by ura on 08.05.16.
//

#ifndef RAYTRACING_SCENE_LOADER_H
#define RAYTRACING_SCENE_LOADER_H


//
// Created by ura on 13.04.16.
//

#include <vector>
#include <string>
#include "fig_primitive.h"
#include "screen.h"
#include "light_source.h"
#include "color.h"
#include "texture_surface.h"
#include "scene.h"

namespace ImGen {

    class LoadException : public std::exception {
        std::string message;
    public:
        virtual const char* what() const noexcept;
        LoadException(const std::string &msg);
        LoadException(const char *spec, ...);
    };

    class Scene;

    class SceneLoader {
        friend class Scene;
        Scene &scene;
    public:

        void load(const char *fileName);
        MetaColor recognizeColor(const char *str);
        TextureSurface *recognizeAndLoadTexture(const char *str);
        void loadFacet(FILE *input, const char *firstString);
        void loadSphere(FILE *input, const char *firstString);
        void loadParallelogram(FILE *input, const char *firstString);
        void loadPlainFacet(FILE *input, const char *firstString);

    private:
        SceneLoader(Scene &scene);
    };

};


#endif //RAYTRACING_SCENE_LOADER_H
