#include "Widget.hpp"
#include "Menu.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

Menu :: Menu(int xx, int yy, int ww, int hh, int oh, std::vector<std::string> value, size_t ak) : Widget(xx, yy, ww, hh)
{
    oph = oh;
    elements = value;
    aktuell = ak;
}

void Menu :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, (y+(h/2))+(gout.cascent()/2)) << text(elements[aktuell]);
}

void Menu :: react(event ev)
{
    int sor = (oph-h)/4;
    if(ev.pos_x > x && ev.pos_x < x + w && ev.pos_y > y && ev.pos_y < y + h)
    {
        gout << color(224, 224, 224) << move_to(x, y-(2*sor)) << box(w, 2*sor);
        gout << move_to(x, y+h) << box(w, 2*sor);
        gout << color(255, 255, 255) << move_to(x, y-sor) << line(w, 0);
        gout << move_to(x, y+h+sor) << line(w, 0);
        if(aktuell > 1)
        {
            gout << color(0,0,0) << move_to(x+2, y-sor-(sor/2)+(gout.cascent()/2)) << text(elements[aktuell-2]);
        }
        if(aktuell > 0)
        {
            gout << color(0,0,0) << move_to(x+2, y-(sor/2)+(gout.cascent()/2)) << text(elements[aktuell-1]);
        }
        if(aktuell < elements.size()-1)
        {
            gout << color(0,0,0) << move_to(x+2, y+h+(sor/2)+(gout.cascent()/2)) << text(elements[aktuell+1]);
        }
        if(aktuell < elements.size()-2)
        {
            gout << color(0,0,0) << move_to(x+2, y+h+sor+(sor/2)+(gout.cascent()/2)) << text(elements[aktuell+2]);
        }
        if(ev.button == btn_wheeldown)
        {
            if(aktuell < elements.size()-1)
            {
                aktuell++;
            }
        }
        if(ev.button == btn_wheelup)
        {
            if(aktuell > 0)
            {
                aktuell--;
            }
        }
    }
    else
    {
        gout << color(0,0,0) << move_to(x, y-(2*sor)) << box(w, 2*sor);
        gout << move_to(x, y+h) << box(w, 2*sor);
    }
}
