//
// Created by ura on 13.04.16.
//

#include <cmath>
#include "color.h"

namespace ImGen {


    unsigned char Color::limitInt(int c) {
        if (c < 0)
            return 0;
        if (c > 255)
            return 255;
        return (uchar)c;
    }

    //Color::Color(uchar r, uchar g, uchar b, uchar state): r(r), g(g), b(b), state(state) { }

    Color::Color(int r, int g, int b, int state): r(limitInt(r)), g(limitInt(g)), b(limitInt(b)), state((uchar)state) { }

    Color::Color(ColorFloatCRef col):
            r(limitInt((int)col.r)), g(limitInt((int)col.g)), b(limitInt((int)col.b)), state(0) {}

    Color Color::operator+(ColorCRef color) const {
        return Color((int)(r + color.r), (int)(g + color.g), (int)(b + color.b), state);
    }
    Color Color::operator*(float k) const {
        return Color((int)(r * k), (int)(g * k), (int)(b * k), state);
    }

    Color::Color() { }

    bool Color::isNan() const {
        return state == 1;
    }

    Color Color::nan() {
        return Color(0, 0, 0, 1);
    }


    ColorFloat ColorFloat::operator+(ColorFloatCRef c) const {
        return ColorFloat(r + c.r, g + c.g, b + c.b);
    }

    ColorFloat ColorFloat::operator-(ColorFloatCRef c) const {
        return ColorFloat(r - c.r, g - c.g, b - c.b);
    }
    ColorFloat ColorFloat::operator*(float k) const {
        return ColorFloat(r * k, g * k, b * k);
    }
    float ColorFloat::norm() const {
        return abs(r) + abs(g) + abs(b);
    }
    ColorFloat::ColorFloat(ColorCRef col): r(col.r), g(col.g), b(col.b) {}
    ColorFloat::ColorFloat(float r, float g, float b): r(r), g(g), b(b) { }

    const std::vector <MetaColor::Field> MetaColor::fields= {
        Field(std::string("background"), MetaColor::Getter([](MetaColor &mc) -> float& { return mc.background; } )),
        Field(std::string("deflective"), MetaColor::Getter([](MetaColor &mc) -> float&  { return mc.deflective; } )),
        Field(std::string("dispersive"), MetaColor::Getter([](MetaColor &mc) -> float&  { return mc.dispersive; } )),
        Field(std::string("glare"), MetaColor::Getter([](MetaColor &mc) -> float&  { return mc.glare; } )),
        Field(std::string("refractive"), MetaColor::Getter([](MetaColor &mc) -> float&  { return mc.refractive; } )),
        Field(std::string("refractive_index"), MetaColor::Getter([](MetaColor &mc)
            -> float&  { return mc.refractiveIndex; } ))
    };


    Color MetaColor::getBackgroundComponent() const {
        return ((Color)*this) * background;
    }
    Color MetaColor::getDispersiveComponent(LightSourceCRef ls, double koef) const {
        double k = koef * dispersive;
        return Color(int(ls.r * r * k), int(ls.g * g * k), int(ls.b * b * k));
    }
    Color MetaColor::getGlareComponent(LightSourceCRef ls, double angleCos, double koef) const {
        if (glare == 0)
            return Color(0, 0, 0);
        double k = pow(angleCos, glare) * koef;
        return Color(int(ls.r * k), int(ls.g * k), int(ls.b * k));
    }
    Color MetaColor::getDeflectiveComponent(const Color &deflected) const {
        return deflected * deflective;
    }
    Color MetaColor::getRefractiveComponent(const Color &refracted) const {
        return refracted * refractive;
    }
    bool MetaColor::isLightSourcesImportant() const {
        return glare > 0 || dispersive > 0;
    }

    MetaColor MetaColor::invert(int s) const {
        if (s == 1 || refractiveIndex == 0)
            return *this;
        else {
            MetaColor color = *this;
            color.refractiveIndex = 1.0f / refractiveIndex;
            return color;
        }
    }

    MetaColor::MetaColor(Color color, float bac, float def, float dis, float gla, float ref, float refInd):
            Color(color), background(bac), deflective(def), dispersive(dis), glare(gla), refractive(ref),
            refractiveIndex(refInd) { }
};