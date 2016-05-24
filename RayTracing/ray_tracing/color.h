//
// Created by ura on 09.04.16.
//

#ifndef RAYTRACING_COLOR_H
#define RAYTRACING_COLOR_H

#include <vector>
#include <functional>
#include "light_source.h"

namespace ImGen {

    class Color;
    typedef const Color &ColorCRef;

    class ColorFloat;
    typedef const ColorFloat &ColorFloatCRef;

    class Color {
        typedef unsigned char uchar;
    public:
        static uchar limitInt(int c);
        unsigned char r, g, b, state;
        static Color nan();
        bool isNan() const;
        Color operator+(ColorCRef color) const;
        Color operator*(float k) const;
        //Color(uchar r, uchar g, uchar b, uchar state = 0);
        explicit Color(int r, int g, int b, int state = 0);
        Color(ColorFloatCRef col);
        Color();
    };

    class ColorFloat {
    public:
        float r, g, b;
        ColorFloat operator+(ColorFloatCRef col2) const;
        ColorFloat operator-(ColorFloatCRef col2) const;
        ColorFloat operator*(float k) const;
        float norm() const;
        ColorFloat(ColorCRef col);
        explicit ColorFloat(float r = 0, float g = 0, float b = 0);
    };


    class MetaColor : public Color {
    public:
        float background, deflective, dispersive, glare, refractive, refractiveIndex;

        typedef std::function<float& (MetaColor&)> Getter;
        typedef std::pair<std::string, Getter> Field;
        static const std::vector <Field> fields;

        Color getBackgroundComponent() const;
        Color getDispersiveComponent(LightSourceCRef lightSource, double koef) const;
        Color getGlareComponent(LightSourceCRef lightSource, double angleCos, double koef) const;
        Color getDeflectiveComponent(ColorCRef deflected) const;
        Color getRefractiveComponent(ColorCRef deflected) const;
        bool isLightSourcesImportant() const;

        MetaColor invert(int s) const;

        MetaColor(Color color = Color(), float bac = 0.3, float def = 0.0,
                  float dis = 0.7, float gla = 0.0, float ref = 0.0, float refInd = 1.0);
    };
    typedef const MetaColor &MetaColorCRef;

};

#endif //RAYTRACING_COLOR_H
