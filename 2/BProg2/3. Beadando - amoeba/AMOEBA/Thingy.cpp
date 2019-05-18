#include "graphics.hpp"
#include "Widget.hpp"
#include "Thingy.hpp"

using namespace std;
using namespace genv;

Thingy :: Thingy(int xx, int yy, int ww, int hh) : Widget(xx, yy, ww, hh)
{
    type = 0;
}

void Thingy :: draw() const
{
    if(type == 0)
    {
        gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
        gout << color(0, 0, 0) << move_to(x+2, y+2) << box(w-4, h-4);
    }
    else if(type == 1)
    {
        gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
        gout << color(255, 0, 0) << move_to(x+2, y+2) << box(w-4, h-4);
    }
    else if(type == 2)
    {
        gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
        gout << color(0, 0, 255) << move_to(x+2, y+2) << box(w-4, h-4);
    }
}

void Thingy :: cht1()
{
    type = 1;
}
void Thingy :: cht2()
{
    type = 2;
}

bool Thingy :: emp()
{
    if(type == 0)
    {
        return true;
    }
    else {return false;}
}

int Thingy :: gtype()
{
    return type;
}
