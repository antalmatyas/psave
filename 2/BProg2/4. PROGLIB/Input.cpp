#include "Widget.hpp"
#include "Input.hpp"
#include "graphics.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;

Input :: Input(int xx, int yy, int ww, int hh) : Widget(xx, yy, ww, hh)
{
    value = "";
}

void Input :: draw() const
{
    gout << color(255,255,255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, y+(h/2)+6) << text(value);
}

void Input :: react(event ev)
{
    if(ev.type==ev_key && 32<=ev.keycode && ev.keycode<=255)
    {
        char c=ev.keycode;
        value.push_back(c);
    }
    if(ev.keycode == key_backspace && value.length() != 0)
    {
        value.pop_back();
    }
    if(gout.twidth(value) > w-2)
    {
        value.pop_back();
    }

}
