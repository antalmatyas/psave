#include "graphics.hpp"
#include <vector>
#include <ctime>
#include <iostream>

using namespace genv;
using namespace std;

int XX, YY;

struct sq
{
    int x, y, sx, sy;
    bool selected;
};

void sqsp(event &ev, vector<sq> &squares)
{
    if(ev.button == btn_right)
    {
        sq a;
        a.x = ev.pos_x;
        a.y = ev.pos_y;
        a.selected = false;
        squares.push_back(a);
    }
}

void draw(vector<sq> &squares)
{
    for(int i = 0 ; i < squares.size() ; i++)
    {
        if(squares[i].selected == true)
        {
            gout << color(255,255,255) << move_to(squares[i].x-2, squares[i].y-2) << box(54, 54);
            gout << color(0,100,200) << move_to(squares[i].x, squares[i].y) << box(50, 50);
        }
        else
        {
            gout << color(255,255,255) << move_to(squares[i].x-2, squares[i].y-2) << box(54, 54);
            gout << color(0,0,255) << move_to(squares[i].x, squares[i].y) << box(50, 50);
        }
    }
}

void click (event &ev, vector<sq> &squares)
{
    if(ev.button == btn_left)
    {
        for(int i = squares.size()-1 ; i>= 0 ; i--)
        {
            if(ev.pos_x >= squares[i].x-2 && ev.pos_x <= squares[i].x+52 && ev.pos_y >= squares[i].y-2 && ev.pos_y <= squares[i].y+52)
            {
                squares[i].selected = true;
                squares[i].sx = ev.pos_x - squares[i].x-2;
                squares[i].sy = ev.pos_y - squares[i].y-2;
                break;
            }
        }
    }
    if(ev.button == -btn_left)
    {
        for(int i = 0 ; i < squares.size() ; i++)
        {
            squares[i].selected = false;
        }
    }
}

void smove(event &ev, vector<sq> &squares)
{
    for(int i = 0 ; i < squares.size() ; i++)
    {
        if(squares[i].selected == true)
        {
            if((ev.pos_x-squares[i].sx) > 54 && (ev.pos_x-squares[i].sx) < (XX-54) && (ev.pos_y-squares[i].sy)>54 && (ev.pos_y-squares[i].sy) < (YY-54))
            squares[i].x = ev.pos_x-squares[i].sx;
            squares[i].y = ev.pos_y-squares[i].sy;
        }
    }
}

void sclear()
{
    gout << color(0,0,0) << move_to(0,0) << box(XX, YY);
}

int main()
{
    XX = 600;
    YY = 600;
    gout.open(XX, YY);
    event ev;
    gin.timer(1);
    vector<sq> squares;
    while(gin >> ev)
    {
        sqsp(ev, squares);
        click(ev, squares);
        if(ev.type == ev_mouse)
        {
            smove(ev, squares);
        }


        if(ev.type == ev_timer)
        {
            sclear();
            draw(squares);
            gout << refresh;
        }

    }
    return 0;
}
