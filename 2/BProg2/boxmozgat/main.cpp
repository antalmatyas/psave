#include "graphics.hpp"
#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <time.h>
#include <stdlib.h>
using namespace genv;
using namespace std;

struct pehely{
int x, y;
pehely(){x = rand() % 500;
        y = rand() % 500;}
pehely(int px, int py) : x(px), y(py) {}
void mozog(){
            x += rand() % 3-1;
            y += rand() % 3;
            if(y >= 500)
            {
                y = 0;
            }
            x = (x+500) % 500;
        }
void rajz(){
    gout << color(255,255,255);
    gout << move_to(x, y) << box(3, 3);}
void more() {}
};

int main()
{
    srand (time(NULL));
    gout.open(500, 500);
    event ev;
    gin.timer(40);
    vector<pehely> ho;
    for(int i = 0 ; i < 1000 ; i++)
    {

        pehely p;
        ho.push_back(p);
    }

    while(gin >> ev && ev.keycode != key_escape) {
        if(ev.type == ev_timer)
        {
            gout << move_to(0,0) << color(0,0,0) << box(500,500);

                for(pehely &p : ho)
            {
                    p.mozog();
            }
            for(pehely p : ho)
            {
                    p.rajz();
            }
            gout << refresh;
        }
        if(ev.button == btn_left)
        {
            for(int i = 0 ; i < 100 ; i++)
            {
            pehely p(ev.pos_x, ev.pos_y);
            ho.push_back(p);
            }
        }
    }
    return 0;
}