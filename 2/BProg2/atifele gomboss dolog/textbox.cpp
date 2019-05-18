#include "textbox.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Textbox::Textbox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    FontSize = 15;
}

void Textbox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << color(255,255,255);

    gout.load_font("LiberationsSans-Regular.ttf", FontSize);
    gout << move_to(_x+3,_y+20);

    gout << text(s);
}

void Textbox::handle(event ev)
{
    if(ev.type == ev_mouse && is_selected(ev.pos_x,ev.pos_y) && ev.button == btn_left)
    {
        _checked = !_checked;
    }
    if(ev.keycode >= 33 && ev.keycode <= 400)
    {
        s += ev.keycode;
        if (gout.twidth(s.substr(0,s.length())) > _size_x-6)
        {
        s = s.substr(0,s.length()-1);
        }
    }
    if(ev.keycode == key_backspace)
    {
        s = s.substr(0,s.length()-1);
    }
}

bool Textbox::is_checked() const
{
    return _checked;
}

void Textbox::action(event ev)
{
}

string Textbox::_getText()
{
    return s;
}
