#include "widget.h"
#include "sinput.h"
#include "graphics.hpp"

#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

sinput :: sinput(int sx,int sy,int sw,int sh)
{
    x = sx;
    y = sy;
    w = sw;
    h = sh;
}

void sinput :: draw() const
{
    gout << color(255,255,255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, y+(h/2)+6) << text(texts);
}

void sinput :: react(event ev)
{


    if(ev.type==ev_key && 32<=ev.keycode && ev.keycode<=255)
    {
        char c=ev.keycode;
        texts.push_back(c);
    }
    if(ev.keycode == key_backspace && texts.length() != 0)
    {
        texts.pop_back();
    }
    if(gout.twidth(texts) > w-2)
    {
        texts.pop_back();
    }

}

void sinput :: save(ofstream &f) const
{
    f << texts << endl;
}

