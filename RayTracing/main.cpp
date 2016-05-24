#include <cstdlib>
#include <ctime>
#include <ratio>
#include <chrono>
#include <CImg.h>
#include <ray_tracing/primitives/fig_triangle.h>
#include <sstream>
#include <ray_tracing/cimg_texture_loader.h>

#include "ray_tracing/scene.h"

namespace cmg = cimg_library;

using IGScreen = ImGen::Screen;
using namespace ImGen;
using namespace std;

string getFileName() {
    using std::chrono::system_clock;
    std::time_t tt;
    tt = system_clock::to_time_t(system_clock::now());
    ostringstream out;
    out << ctime(&tt);
    std::string str = out.str();
    str.resize(str.size() - 1);
    return str;

}

int main() {


    Scene scene = Scene();
    scene.setTextureLoader(new ImGen::CImgTextureLoader());
    scene.getSceneLoader().load("models/model.stl");

    int W = scene.getScreen().width, H = scene.getScreen().height;
    cerr << W << " " << H << endl;
    cmg::CImg<unsigned char> visu(W,H,1,3,0);


    std::string fName = getFileName();
    cmg::CImgDisplay draw_disp(visu, fName.c_str());


    int cnt = 0;
            /*.setScreen(IGScreen(Parallelogram(Point(0, 1, 1), Point(0, -2, 0), Point(0, 0, -2)), W, H))
            .setSpectator(Point(-2, 0, 0))
            .add(new Triangle(Point(1, -1, -1), Point(1, 1, -1), Point(10, 1, 1), Color(255, 0, 0)))
            .add(new Triangle(Point(1, -1, -1), Point(1, 1, -1), Point(10, -1, 1), Color(0, 255, 0)));
            */

    cerr << "started visualize" << endl;
    scene.computeColorsAntialiasing([&visu, &draw_disp, &cnt](int x, int y, ColorCRef color) {
        visu(x, y, 0, 0) = color.r;
        visu(x, y, 0, 1) = color.g;
        visu(x, y, 0, 2) = color.b;
        if (++cnt % 1000 == 0)
            visu.display(draw_disp);
    }, 2, 2);
    cerr << "visualized!" << endl;
    visu.save_jpeg(("pictures_log/" + fName + ".jpeg").c_str());
    visu.display(draw_disp);
    //pause();
    while (!draw_disp.is_closed()) {
        draw_disp.wait();
        if (draw_disp.button() && draw_disp.mouse_y()>=0) {
            visu(draw_disp.mouse_x(), draw_disp.mouse_y(), 0, 1) = 255;
            visu.display(draw_disp);
        }
    }
    return 0;
}
