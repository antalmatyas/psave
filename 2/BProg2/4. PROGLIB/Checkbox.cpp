#include "Widget.hpp"
#include "Checkbox.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

Checkbox :: Checkbox(int xx, int yy, int ww, int hh) : Widget(xx, yy, ww, hh)
{
    checked = false;
}

void Checkbox :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, y+2) << box(w-4, h-4);
    if(checked)
    {
        gout << color(255, 255, 255) << move_to((x+(w/2)-5), (y+(h/2)-5)) << box(10,10);
    }
}

void Checkbox :: react(event ev)
{
    if(ev.button == btn_left && ev.pos_x > x && ev.pos_x < x+w && ev.pos_y > y && ev.pos_y < y+h)
    {
        checked = !checked;
    }
}
