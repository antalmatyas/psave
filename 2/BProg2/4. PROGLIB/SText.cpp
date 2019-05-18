#include "Widget.hpp"
#include "SText.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

SText :: SText(int xx, int yy, int ww, int hh, string vv) : Widget(xx, yy, ww, hh)
{
    vstring = vv;
}

void SText :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, (y+(h/2)+(gout.cascent()/2))) << text(vstring);
}
