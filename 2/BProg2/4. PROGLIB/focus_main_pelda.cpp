#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include "graphics.hpp"
#include "widget.h"
#include "nums.h"
#include "slist.h"

using namespace std;
using namespace genv;

vector<string> gen1 ()
{
    vector<string> dolog;
    string w1 = "1hallo";
    string w2 = "2ballo";
    string w3 = "3tallo";
    string w4 = "4gallo";
    string w5 = "5lallo";
    dolog.push_back(w1);
    dolog.push_back(w2);
    dolog.push_back(w3);
    dolog.push_back(w4);
    dolog.push_back(w5);

    return dolog;
}

vector<string> gen2 ()
{
    vector<string> dolog;
    string w1 = "vvvv";
    string w2 = "sssss";
    string w3 = "ttt";
    string w4 = "zzzz";
    dolog.push_back(w1);
    dolog.push_back(w2);
    dolog.push_back(w3);
    dolog.push_back(w4);

    return dolog;
}

int main()
{

    vector<string> dolog = gen1();
    vector<string> valami = gen2();
    gout.open(600, 600);
    gout << move_to(2, 588) << color(255, 255, 255) << text("Press 'Enter' to save selected data");
    nums *a = new nums(50, 50, 80, 25, 100, 90, 150);
    nums *b = new nums(250, 50, 80, 25, 55, 50, 60);
    // (x pos, y pos, width, height, value, min, max)

    slist *c = new slist(50, 210, 80, 25, 125, dolog, 0);
    slist *d = new slist(250, 210, 100, 25, 150, valami, 1);
    // (x pos, y pos, csukott width, csukott height, nyitott width, nyitott height,  lista, kiválasztott)

    c->newobj("asdasdasd");
    d->newobj("ujjjjj");

    vector<widget*> widgets;
    widgets.push_back(a);
    widgets.push_back(b);
    widgets.push_back(c);
    widgets.push_back(d);

    event ev;
    int active = -1;
    while(gin >> ev)
    {
        if(ev.keycode == key_enter)
        {
            ofstream mentes;
            mentes.open("save.txt");
            a->save(mentes);
            b->save(mentes);
            c->save(mentes);
            d->save(mentes);
            gout << color(255,0,0) << move_to(500, 588) << text("data saved");
        }
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            for(size_t i = 0 ; i < widgets.size() ; i++)
            {
                if(widgets[i]->selected(ev.pos_x, ev.pos_y))
                {
                    active = i;
                }
            }
        }
        if(active != -1)
        {
            widgets[active]->react(ev);
        }
        for(size_t i = 0 ; i < widgets.size() ; i++)
        {
            widgets[i]->draw();
        }
        gout << refresh;
    }

    return 0;
}
