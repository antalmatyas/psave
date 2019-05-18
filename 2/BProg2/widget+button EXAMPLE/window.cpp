#include "window.hpp"
using namespace genv;

void Window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_key && ev.keycode == key_tab) {
            if(focus!=-1) {
                widgets[focus]->unfocus();
            }
            do {
                focus++;
                if (focus>=widgets.size()) focus =0;
            } while (!widgets[focus]->focusable()); //TODO:vegtelenciklus!
            widgets[focus]->focus();
        }
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y) && widgets[i]->focusable()) {
                        if (focus!=-1) widgets[focus]->unfocus();
                        focus = i;
                        widgets[focus]->focus();
                }
            }
        }
        if (focus!=-1) {
            widgets[focus]->handle(ev);
        }
        for (size_t i=0;i<widgets.size();i++) {
            widgets[i]->draw();
        }
        gout << refresh;
    }
}
