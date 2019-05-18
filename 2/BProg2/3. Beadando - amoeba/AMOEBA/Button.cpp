#include "graphics.hpp"
#include "Widget.hpp"
#include "Button.hpp"

using namespace std;
using namespace genv;

Button :: Button(int xx, int yy, int ww, int hh, string s) : Widget(xx, yy, ww, hh)
{
    out = s;
}
void Button :: draw() const
{
    gout << color(255, 255, 255) << move_to(x, y) << box(w, h);
    gout << color(0, 0, 0) << move_to(x+2, y+2) << box(w-4, h-4);
    gout << color(255, 255, 255) << move_to(x+(w/2)-(gout.twidth(out)/2), y+(h/2)+5) << text(out);
}

bool Button :: active(genv::event ev)
{
    if(ev.pos_x > x && ev.pos_x < x+w && ev.pos_y > y && ev.pos_y < y+h)
    {
        return true;
    }
    else
    {
        return false;
    }
}
