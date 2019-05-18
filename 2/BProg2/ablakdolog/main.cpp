#include "graphics.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

using namespace genv;
using namespace std;
int XX, YY, ac;

struct cc
{
    int x, y, s, cx, cy;
    bool selected;
};

void newblock(event &ev, vector<cc> &blocks)
{
    if(ev.button == btn_right)
    {
        cc a;
        a.x = ev.pos_x;
        a.y = ev.pos_y;
        a.s = 80;
        a.selected = false;
        blocks.push_back(a);
    }
}

void draw(vector<cc> &blocks)
{
    for(int i = 0 ; i < blocks.size() ; i++)
    {
        if(blocks[i].selected == true)
        {
            gout << color(255,255,255) << move_to(blocks[i].x-2, blocks[i].y-2) << box(blocks[i].s+4, blocks[i].s+4);
            gout << color(0,0,200) << move_to(blocks[i].x, blocks[i].y) << box(blocks[i].s, blocks[i].s);
        }
        else
        {
            gout << color(255,255,255) << move_to(blocks[i].x-2, blocks[i].y-2) << box(blocks[i].s+4, blocks[i].s+4);
            gout << color(0,0,255) << move_to(blocks[i].x, blocks[i].y) << box(blocks[i].s, blocks[i].s);
        }
    }
}

void click(event &ev, vector<cc> &blocks)
{
    if(ev.button == btn_left)
    {
        for(int i = 0 ; i < blocks.size() ; i++)
        {
            if(blocks[i].x <= ev.pos_x && blocks[i].x+blocks[i].s >= ev.pos_x && blocks[i].y <= ev.pos_y && blocks[i].y+blocks[i].s >= ev.pos_y)
            {
                cout << "dolog";
                blocks[i].selected = true;
                blocks[i].cx = ev.pos_x-blocks[i].x;
                blocks[i].cy = ev.pos_y-blocks[i].y;
                ac = i;
            }
        }
    }
    else
    {
        for(int i = 0 ; i < blocks.size() ; i++)
        {
            blocks[i].selected = false;
        }
    }
}

void bmove(event &ev, vector<cc> &blocks)
{
    blocks[ac].x = ev.pos_x-blocks[ac].cx;
    blocks[ac].y = ev.pos_y-blocks[ac].cy;
}

int main()
{
    vector<cc> blocks;
    XX = 600;
    YY = 600;
    gout.open(XX, YY);
    event ev;
    gin.timer(2);
    while(gin >> ev)
    {
        if(ev.type == ev_timer)
        {
            //bmove(ev, blocks);
            draw(blocks);
            gout << refresh;
        }
        newblock(ev, blocks);
        click(ev, blocks);

    }
    return 0;
}
