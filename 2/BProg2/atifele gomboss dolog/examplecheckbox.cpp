#include "examplecheckbox.hpp"
#include "graphics.hpp"
using namespace genv;

ExampleCheckBox::ExampleCheckBox(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
}

void ExampleCheckBox::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
    gout << move_to(_x+10, _y+19) << color(255,255,255) << text("=");
}

void ExampleCheckBox::handle(event ev)
{
    if (ev.type == ev_key && (ev.keycode == key_enter || ev.keycode == ' ')) {
            _checked = !_checked;
    }
    if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        _checked = !_checked;
    }
}
bool ExampleCheckBox::is_checked() const
{
    return _checked;
}
