#include "texteditor.hpp"
#include <string>
using namespace std;
using namespace genv;

TextEditor::TextEditor(int x, int y, int sx, int sy, string s) : Widget(x,y,sx,sy) {_s=s;}
void TextEditor::draw() const {
    if (_focused) {
        gout << color(255,255,255);
    } else {
        gout << color(155,155,155);
    }
    gout << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(0,0,0) << move_to(_x+1, _y+1) << box(_size_x-2, _size_y-2);
    gout << move_to(_x+3,_y+gout.cascent()+5) << color(255,255,255) << text(_s);
    if (_focused) gout <<text("|");
}
void TextEditor::handle(event ev) {
    if (ev.type == ev_key) {
        if (ev.keycode >= ' ' && ev.keycode < 255) {
            _s += ev.keycode;
            if (_size_x < 10+gout.twidth(_s) ) {
                _s = _s.substr(0,_s.length()-1);
            }
        }
        if (ev.keycode == key_backspace) {
            _s = _s.substr(0,_s.length()-1);
        }
    }
}
