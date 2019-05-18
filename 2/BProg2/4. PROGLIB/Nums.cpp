#include "Widget.hpp"
#include "Nums.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

stringstream ss;
string svalue;

Nums :: Nums(int xx, int yy, int ww, int hh, int value, int minimum, int maximum) : Widget(xx, yy, ww, hh)
{
    val = value;
    vmin = minimum;
    vmax = maximum;
}

void Nums :: draw() const
{
    ss.clear();
    ss << val;
    ss >> svalue;
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, (y+(h/2)+(gout.cascent()/2))) << text(svalue);
    gout << move_to(x+w-20, y) << line(0, h);
    gout << move_to(x+w-20, y+(h/2)) << line(20, 0);
    gout << move_to(x+w-13, y+(h/4)+5) << text("+");
    gout << move_to(x+w-13, y+3*(h/4)+5) << text("-");
}

void Nums :: react(event ev)
{
    if(val>vmin)
    {
        if(ev.keycode == key_down || (ev.button == btn_left && ev.pos_x > x+w-20 && ev.pos_x<x+w && ev.pos_y>y+(h/2) && ev.pos_y<y+h))
        {
            val--;
        }
        else if(ev.keycode == key_pgdn)
        {
            if(val >= vmin + 10)
            {
                val -= 10;
            }
            else
            {
                val = vmin;
            }
        }
    }

    if(val<vmax)
    {
        if(ev.keycode == key_up  || (ev.button == btn_left && ev.pos_x > x+w-20 && ev.pos_x<x+w && ev.pos_y>y && ev.pos_y<y+(h/2)))
        {
            val++;
        }
        else if(ev.keycode == key_pgup)
        {
            if(val <= vmax - 10)
            {
                val += 10;
            }
            else
            {
                val = vmax;
            }
        }
    }
}

