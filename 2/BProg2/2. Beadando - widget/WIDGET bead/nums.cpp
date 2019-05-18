#include "widget.h"
#include "nums.h"
#include "graphics.hpp"
#include <stdio.h>

#include <sstream>

using namespace std;
using namespace genv;

stringstream ss;

string svalue;

nums :: nums(int sx,int sy,int sw,int sh,int value,int vminimum,int vmaximum)
{
    x = sx;
    y = sy;
    w = sw;
    h = sh;
    val = value;
    vmin = vminimum;
    vmax = vmaximum;
}

void nums :: draw() const
{
    ss.clear();
    ss << val;
    ss >> svalue;
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0,0,0) << move_to(x+2, (y+(h/2))+(gout.cascent()/2)) << text(svalue);
    gout << move_to(x+w-20, y) << line(0, h);
    gout << move_to(x+w-20, y+(h/2)) << line(20, 0);
    gout << move_to(x+w-13, y+(h/4)+5) << text("+");
    gout << move_to(x+w-13, y+3*(h/4)+5) << text("-");
}

void nums :: react(event ev)
{
    if(val>vmin)
    {
        if(ev.keycode == key_down || ev.keycode == key_pgdn || (ev.button == btn_left && ev.pos_x > x+w-20 && ev.pos_x<x+w && ev.pos_y>y+(h/2) && ev.pos_y<y+h))
        {
            val--;
        }
    }

    if(val<vmax)
    {
        if(ev.keycode == key_up || ev.keycode == key_pgup || (ev.button == btn_left && ev.pos_x > x+w-20 && ev.pos_x<x+w && ev.pos_y>y && ev.pos_y<y+(h/2)))
        {
            val++;
        }
    }
}
