#include "graphics.hpp"
#include <vector>
#include <ctime>
#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

int XX, YY;
stringstream str1;
string str2;


struct sq
{
    int x, y, sx, sy, g, w, h;
    bool selected, resiz;
};

void sqsp(event &ev, vector<sq> &squares)
{
    if(ev.button == btn_right)
    {
        sq a;
        a.x = ev.pos_x;
        a.y = ev.pos_y;
        a.g = 60;
        a.w = 60;
        a.h = 60;
        a.selected = false;
        a.resiz = false;
        squares.push_back(a);
    }
}

void draw(vector<sq> &squares)
{
    for(int i = 0 ; i < squares.size() ; i++)
    {
        if(squares[i].selected == true)
        {
            gout << color(255,255,255) << move_to(squares[i].x-2, squares[i].y-2) << box(squares[i].w+4, squares[i].h+4);
            gout << color(0,100,200) << move_to(squares[i].x, squares[i].y) << box(squares[i].w, squares[i].h);
            str1 << squares[i].g;
            str1 >> str2;
            gout << color(255,255,255) << move_to(squares[i].x+(squares[i].w/2)-4, squares[i].y+(squares[i].h/2)) << text(str2);
            gout << color(0, 200, 0) << move_to(squares[i].x+squares[i].w-6, squares[i].y+squares[i].h-6) << box(8, 8);
            str1.clear();

        }
        if(squares[i].selected == false)
        {
            gout << color(255,255,255) << move_to(squares[i].x-2, squares[i].y-2) << box(squares[i].w+4, squares[i].h+4);
            gout << color(0,0,255) << move_to(squares[i].x, squares[i].y) << box(squares[i].w, squares[i].h);
            str1 << squares[i].g;
            str1 >> str2;
            gout << color(255,255,255) << move_to(squares[i].x+(squares[i].w/2)-4, squares[i].y+(squares[i].h/2)) << text(str2);
            gout << color(0, 200, 0) << move_to(squares[i].x+squares[i].w-6, squares[i].y+squares[i].h-6) << box(8, 8);
            str1.clear();
        }
    }
}

void click (event &ev, vector<sq> &squares)
{
    if(ev.button == btn_left)
    {
        for(int i = squares.size()-1 ; i>= 0 ; i--)
        {
            if(ev.pos_x < squares[i].x+squares[i].w+2 && ev.pos_x > squares[i].x+squares[i].w-6 && ev.pos_y < squares[i].y+squares[i].h+2 && ev.pos_y > squares[i].y+squares[i].h-6)
            {
                squares[i].resiz = true;
                squares[i].sx = ev.pos_x - squares[i].x-2;
                squares[i].sy = ev.pos_y - squares[i].y-2;
                break;
            }
            else if(ev.pos_x >= squares[i].x-2 && ev.pos_x <= squares[i].x+squares[i].w+2 && ev.pos_y >= squares[i].y-2 && ev.pos_y <= squares[i].y+squares[i].h+2)
            {
                squares[i].selected = true;
                squares[i].sx = ev.pos_x - squares[i].x;
                squares[i].sy = ev.pos_y - squares[i].y;
                break;
            }
        }
    }
    if(ev.button == -btn_left)
    {
        for(int i = 0 ; i < squares.size() ; i++)
        {
            squares[i].selected = false;
            squares[i].resiz = false;
        }
    }
    if(ev.button == btn_wheeldown)
    {
        for(int i = squares.size()-1 ; i>= 0 ; i--)
        {
            if(ev.pos_x >= squares[i].x-2 && ev.pos_x <= squares[i].x+squares[i].w+2 && ev.pos_y >= squares[i].y-2 && ev.pos_y <= squares[i].y+squares[i].h+2)
            {
                squares[i].g--;
                break;
            }
        }
    }
    if(ev.button == btn_wheelup)
    {
        for(int i = squares.size()-1 ; i>= 0 ; i--)
        {
            if(ev.pos_x >= squares[i].x-2 && ev.pos_x <= squares[i].x+squares[i].w+2 && ev.pos_y >= squares[i].y-2 && ev.pos_y <= squares[i].y+squares[i].h+2)
            {
                squares[i].g++;
                break;
            }
        }
    }
}

void smove(event &ev, vector<sq> &squares)
{
    for(int i = 0 ; i < squares.size() ; i++)
    {
        if(squares[i].selected == true && ev.pos_x > squares[i].sx+2 && ev.pos_y > squares[i].sy+2 && ev.pos_x < XX-(squares[i].w+2-squares[i].sx) && ev.pos_y < YY-(squares[i].h+2-squares[i].sy))
        {
            squares[i].x = ev.pos_x-squares[i].sx;
            squares[i].y = ev.pos_y-squares[i].sy;
        }
    }
}

void resizing(event &ev, vector<sq> &squares)
{
    for(int i = 0 ; i < squares.size() ; i++)
    {
        if(squares[i].resiz == true && ev.pos_x > squares[i].x && ev.pos_y > squares[i].y)
        {
            squares[i].w = ev.pos_x - squares[i].x;
            squares[i].h = ev.pos_y - squares[i].y;
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
    vector<sq> squares;
    while(gin >> ev && ev.keycode != key_escape)
    {
        sclear();
        sqsp(ev, squares);
        click(ev, squares);
        smove(ev, squares);
        resizing(ev, squares);
        draw(squares);
        gout << refresh;
    }
    return 0;
}
