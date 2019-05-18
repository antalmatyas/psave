#include "graphics.hpp"
#include "widgets.hpp"
#include "examplecheckbox.hpp"
#include <vector>
#include "textbox.hpp"
#include "writer.hpp"
using namespace std;
using namespace genv;

class MyWidget : public Textbox
{
public:
    //MyWidget(int x, int y, int sx, int sy); //: Textbox(x,y,sx,sy){}
    MyWidget (int x, int y, int sx, int sy) : Textbox(x,y,sx,sy){};
    virtual void draw() const
    {
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout << color(255,255,255);

    gout.load_font("LiberationsSans-Regular.ttf", FontSize);
    gout << move_to(_x+3,_y+20);

    gout << text(s);
    }
    virtual void handle(genv::event ev)
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
    virtual void action(genv::event ev)
    {
    }
    virtual bool is_checked() const
    {
    }
};
class OkButton : public ExampleCheckBox
{
private:
    MyWidget * tb;
    Writer * wr;
public:
    OkButton(int x, int y, int sx, int sy, MyWidget * asd, Writer * dsa) : ExampleCheckBox(x,y,sx,sy){
    tb = asd;
    wr = dsa;
    };
    virtual void draw() const
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+10, _y+19) << color(255,255,255) << text("=");
    }
    virtual void handle(genv::event ev)
    {
        if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        wr->AddElements(tb->_getText());
    }
    }
    virtual bool is_checked() const
    {
    }
};
class DelButton : public ExampleCheckBox
{
private:
    Writer * wr;
public:
    DelButton(int x, int y, int sx, int sy, Writer * dsa) : ExampleCheckBox(x,y,sx,sy){
    wr = dsa;
    };
    virtual void draw() const
    {
        gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
        gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);
        gout << move_to(_x+10, _y+19) << color(255,255,255) << text("/");
    }
    virtual void handle(genv::event ev)
    {
        if (ev.type == ev_mouse && is_selected(ev.pos_x, ev.pos_y) && ev.button==btn_left) {
        wr->DelElements();
    }
    }
    virtual bool is_checked() const
    {
    }
};

void event_loop(vector<Widget*>& widgets) {
    event ev;
    int focus = -1;
    while(gin >> ev ) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgets.size();i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
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

int main()
{
    gout.open(400,400);
    vector<Widget*> w;

    //ExampleCheckBox * b2 = new ExampleCheckBox(10,50,30,30);
    Writer * b3 = new Writer (150,10,200,200);
    MyWidget * b4 = new MyWidget (10,10,100,30);
    OkButton * b1 = new OkButton(10,50,30,30, b4, b3);
    DelButton * b2 = new DelButton (10,90,30,30, b3);
    w.push_back(b1);
    w.push_back(b2);
    w.push_back(b3);
    w.push_back(b4);
    event_loop(w);
    return 0;
}
