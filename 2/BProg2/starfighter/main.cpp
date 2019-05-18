#include "graphics.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cmath>
using namespace genv;
using namespace std;

int XX, YY;

struct sh{int x, y, s, sp, hs;};

void starsp(vector<sh> &starz){
for(int i = 0 ; i < 10 ; i++)
    {
        sh a;
        a.x = rand() % XX;
        a.y = rand() % YY;
        a.s = 4;
        a.sp = 10;
        starz.push_back(a);
    }
    for(int i = 0 ; i < 40 ; i++)
    {
        sh a;
        a.x = rand() % XX;
        a.y = rand() % YY;
        a.s = 2;
        a.sp = 3;
        starz.push_back(a);
    }
    for(int i = 0 ; i < 200 ; i++)
    {
        sh a;
        a.x = rand() % XX;
        a.y = rand() % YY;
        a.s = 1;
        a.sp = 2;
        starz.push_back(a);
    }
}

void starmove(vector<sh> &starz)
{
    for(int i = 0 ; i < starz.size() ; i++)
    {
        starz[i].y += starz[i].sp;
        if(starz[i].y > YY)
        {
            starz[i].y = 0;
            starz[i].x = rand() % XX;
        }
    }
}

void stdraw(vector<sh> &starz)
{
    gout <<color(255,255,255);
    for(int i  = 0 ; i < starz.size() ; i++)
    {
        gout << move_to(starz[i].x, starz[i].y) << box(starz[i].s, starz[i].s);
    }
}

void sclear()
{
    gout << color(0,0,0) << move_to(0,0) << box (XX, YY);
}

void shipmove(sh &ship, event &ev)
{
    if(ev.keycode == key_down)
        {
            if(ship.y+ship.sp+ship.hs < YY)
            {
              ship.y += ship.sp;
            }
        }
    if(ev.keycode == key_up)
        {
            if(ship.y-ship.sp-ship.hs > 0)
            {
              ship.y -= ship.sp;
            }
        }
    if(ev.keycode == key_right)
        {
            if(ship.x+ship.sp+ship.hs < XX)
            {
              ship.x += ship.sp;
            }
        }
    if(ev.keycode == key_left)
        {
            if(ship.x-ship.sp-ship.hs > 0)
            {
              ship.x -= ship.sp;
            }
        }
}

void shipdraw(sh &ship)
{
    gout << color(0,0, 155) << move_to(ship.x, ship.y) << box(ship.hs,ship.hs);
    gout << color(255,255,255) << move_to(ship.x-ship.hs, ship.y) << box(ship.hs,ship.hs);
    gout << color(0,255,255) << move_to(ship.x, ship.y-ship.hs) << box(ship.hs,ship.hs);
    gout << color(255,255,0) << move_to(ship.x-ship.hs, ship.y-ship.hs) << box(ship.hs,ship.hs);

}

void shotsp(vector<sh> &shot, event &ev, sh &ship)
{
    if(ev.keycode == key_space)
    {sh a;
    a.x = ship.x;
    a.y = ship.y-ship.hs-3,
    a.sp = 3;
    shot.push_back(a);
    }
}

void shoot(vector<sh> &shot)
{
    for(int i = 0 ; i < shot.size() ; i++)
    {
        shot[i].y -= shot[i].sp;
        shot[i].x += rand() % 2;
        shot[i].x -= rand() % 2;
        if(shot[i].y < 0)
        {
            shot.erase(shot.begin()+i);
        }
    }
}

void shotdraw(vector<sh> &shot)
{
    for(int i = 0 ; i < shot.size() ; i ++)
    {
        gout << color(255,0,0) << move_to(shot[i].x, shot[i].y) << box(5,5);
    }
}

void ensp(vector<sh> &enemy)
{
    for(int i = 0 ; i < 6 ; i++)
    {
        sh a;
        a.x = rand() % XX;
        a.y = 5;
        a.sp = 2;
        a.s = 50;
        enemy.push_back(a);
    }
}

void enmove(vector<sh> &enemy)
{
    for(int i = 0 ; i < enemy.size() ; i++)
    {
        enemy[i].y += rand() % enemy[i].sp;
        if(enemy[i].x + 5 + enemy[i].s < XX)
        {
            enemy[i].x += rand() % 5;
        }
        if(enemy[i].x - 5 > 0)
        {
            enemy[i].x -= rand() % 5;
        }
    }
}

void endraw(vector<sh> &enemy)
{
    for(int i = 0 ; i < enemy.size() ; i++)
    {
        gout << color(255,160,0) << move_to(enemy[i].x, enemy[i].y) << box(enemy[i].s, enemy[i].s);
    }
}

void hit(vector<sh> &enemy, vector<sh> &shot)
{
    for(int i = 0 ; i < shot.size() ; i++)
    {
        for(int j = 0 ; j < enemy.size() ; j++)
        {
            if(shot[i].y == enemy[j].y + enemy[j].s)
            {
                if(enemy[j].x < shot[i].x || shot[i].x < enemy[j].x + enemy[j].s)
                {
                    enemy.erase(enemy.begin()+j);
                    shot.erase(shot.begin()+i);
                }
            }
        }
    }
}

int main()
{
    srand(time(0));
    XX = 600;
    YY = 600;
    gout.open(XX,YY);
    event ev;
    gin.timer(20);
    sh ship;
    ship.x = 300;
    ship.y = 500;
    ship.s = 40;
    ship.sp = 20;
    ship.hs = ship.s/2;
    vector<sh> starz;
    starsp(starz);
    vector<sh> shot;
    vector<sh> enemy;
    ensp(enemy);
    while(gin >> ev && ev.keycode != key_escape) {
            shipmove(ship, ev);
            shotsp(shot, ev, ship);
    if(ev.type == ev_timer)
    {
        sclear();
        starmove(starz);
        stdraw(starz);
        shipdraw(ship);
        shoot(shot);
        shotdraw(shot);
        enmove(enemy);
        endraw(enemy);
        hit(enemy, shot);
        gout << refresh;
    }
    }
    return 0;
}
