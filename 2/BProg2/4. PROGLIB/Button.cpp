#include "Widget.hpp"
#include "Button.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

Button :: Button(int xx, int yy, int ww, int hh, std::string vv) : Widget(xx, yy, ww, hh)
{
    label = vv;
}

void Button :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, (y+(h/2)+(gout.cascent()/2))) << text(label);
}

bool Button :: react(genv::event ev)
{
    if(ev.button == btn_left && ev.pos_x > x && ev.pos_x < x+w && ev.pos_y > y && ev.pos_y < y+h)
    {
        return true;
    }
    else
    {
        return false;
    }
}
