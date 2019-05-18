#include "widget.h"
#include "graphics.hpp"
#include <vector>
using namespace std;
using namespace genv;

bool widget :: selected(int xx, int yy) const
{
    if(xx>x && xx<x+w && yy > y && yy < y+h)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void widget::draw() const {}
//void widget::react(event ev) {}
