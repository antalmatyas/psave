#include "Widget.hpp"
#include "graphics.hpp"
#include <vector>
using namespace std;
using namespace genv;

Widget :: Widget(int xx, int yy, int ww, int hh)
{
    x = xx;
    y = yy;
    w = ww;
    h = hh;
}

bool Widget :: selected(int xx, int yy) const
{
    if(xx > x && xx < x+w && yy > y && yy < y+h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Widget :: draw() const {}
