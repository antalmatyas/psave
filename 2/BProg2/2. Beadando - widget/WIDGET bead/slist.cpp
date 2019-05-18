#include <stdio.h>
#include <vector>
#include <sstream>
#include "slist.h"
#include "widget.h"
#include "graphics.hpp"

using namespace std;
using namespace genv;

slist :: slist(int sx,int sy,int sw,int sh, int nh, std::vector<std::string> value, size_t ak)
{
    x = sx;
    y = sy;
    w = sw;
    h = sh;
    oph = nh;
    lista = value;
    aktuell = ak;
}

void slist :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, (y+(h/2))+(gout.cascent()/2)) << text(lista[aktuell]);
}

void slist :: react(event ev)
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
            gout << color(0,0,0) << move_to(x+2, y-sor-(sor/2)+(gout.cascent()/2)) << text(lista[aktuell-2]);
        }
        if(aktuell > 0)
        {
            gout << color(0,0,0) << move_to(x+2, y-(sor/2)+(gout.cascent()/2)) << text(lista[aktuell-1]);
        }
        if(aktuell < lista.size()-1)
        {
            gout << color(0,0,0) << move_to(x+2, y+h+(sor/2)+(gout.cascent()/2)) << text(lista[aktuell+1]);
        }
        if(aktuell < lista.size()-2)
        {
            gout << color(0,0,0) << move_to(x+2, y+h+sor+(sor/2)+(gout.cascent()/2)) << text(lista[aktuell+2]);
        }
        if(ev.button == btn_wheeldown)
        {
            if(aktuell < lista.size()-1)
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

void slist :: newobj(string a)
{
    lista.push_back(a);
}
