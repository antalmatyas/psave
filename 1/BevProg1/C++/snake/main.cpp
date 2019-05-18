#include "graphics.hpp"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <sstream>

using namespace genv;
using namespace std;

int XX, YY, d , s, score, selected;
stringstream ss;
string sc;
bool gameon, c;

struct bl{int x, y;};

void spawn(vector<bl> &snake)
{
    for(int i = 0 ; i < 4 ; i++)
    {
        bl a;
        a.x = XX/2;
        a.y = YY/2;
        snake.push_back(a);
    }
        d = 1;
        s = 20;
        score = 0;
}


void draw(vector<bl> &snake, vector<bl> &kaja, vector<bl> &wall)
{
    for(int i = 0 ; i < wall.size() ; i++)
    {
        gout << color(150, 150, 150) << move_to(wall[i].x, wall[i].y) << box(s,s);
    }
    for(int i = 0 ; i < snake.size() ; i++)
    {
        gout << color(50, 200, 70) << move_to(snake[i].x, snake[i].y) << box(s,s);
    }
    if(kaja.size() != 0)
    {
        gout << color(255,0,0) << move_to(kaja[0].x, kaja[0].y) << box(s, s);
    }
    ss.clear();
    ss << score;
    ss >> sc;
    gout << move_to(0,15) << text("SCORE: ") << text(sc);
}

void smove(vector<bl> &snake)
{
    for(int i = snake.size() ; i > 0 ; i--)
    {
        snake[i].x = snake[i-1].x;
        snake[i].y = snake[i-1].y;
    }
    if(d == 1)
    {
        if((snake[0].x + s) < XX)
        {
            snake[0].x += s;
        }
        else{snake[0].x = 0;}

    }
    if(d == 2)
    {
        if((snake[0].y - s) >= 0)
        {
            snake[0].y -= s;
        }
        else{snake[0].y = YY-s;}
    }
    if(d == 3)
    {
        if((snake[0].x - s) >= 0)
        {
            snake[0].x -= s;
        }
        else{snake[0].x = XX-s;}
    }
    if(d == 4)
    {
        if((snake[0].y + s) < YY)
        {
            snake[0].y += s;
        }
        else{snake[0].y = 0;}
    }
}

void control(event &ev, bool &c)
{
    if(ev.keycode == key_right && d != 3 && c == true)
    {
        d = 1;
        c = false;
    }
        if(ev.keycode == key_up && d != 4 && c == true)
    {
        d = 2;
        c = false;
    }
        if(ev.keycode == key_left && d != 1 && c == true)
    {
        d = 3;
        c = false;
    }
        if(ev.keycode == key_down && d != 2 && c == true)
    {
        d = 4;
        c = false;
    }
}

void sclear()
{
    gout << color(0,0,0) << move_to(0,0) << box(XX, YY);
}

void fspawn(vector<bl> &kaja, vector<bl> &wall)
{
    if(kaja.size() == 0)
    {
        bl a;
        a.x = s*(rand() % (XX/s));
        a.y = s*(rand() % (YY/s));
        bool indawall = false;
        for(int i = 0 ; i < wall.size() ; i++)
        {
            if(wall[i].x == a.x && wall[i].y == a.y)
            {
                indawall = true;
            }
        }
        if(indawall == false)
        {
            kaja.push_back(a);
        }
    }
}

void feded(vector<bl> &snake, vector<bl> &kaja)
{
    if(snake[0].x == kaja[0].x && snake[0].y == kaja[0].y)
    {
        kaja.erase(kaja.begin());
        bl a;
        snake.push_back(a);
        score++;
    }
}

void crash(vector<bl> &snake, vector<bl> &wall)
{
    for(int i = 1 ; i < snake.size() ; i++)
    {
        for(int j  = 0 ; j < wall.size() ; j++)
        {
           if((snake[0].x == snake[i].x && snake[0].y == snake[i].y) || (snake[i].x == wall[j].x && snake[i].y == wall[j].y) )
            {
                exit(0);
            }
        }

    }
}

void cwall(vector<bl> &wall)
{
    for(int i = 0 ; i <= (XX-s)/s ; i++)
    {
        bl a;
        a.y = 0;
        a.x = s*i;
        wall.push_back(a);
    }
    for(int i = 0 ; i <= (XX-s)/s ; i++)
    {
        bl a;
        a.y = YY-s;
        a.x = s*i;
        wall.push_back(a);
    }
    for(int i = (YY/3) ; i < 2*(YY/3) ; i++)
    {
        bl a;
        a.y = i;
        a.x = (XX/3);
        wall.push_back(a);
    }
}

bool menu(event &ev)
{
    if(ev.keycode == key_down)
    {
        selected +=1;
    }

    if(ev.keycode == key_up)
    {
        selected -=1;
    }
    if(ev.keycode == key_enter)
    {
        if(selected == 0)
        {
            gameon = true;
            return;
        }
        if(selected == 1)
        {
            exit(0);
        }
    }
}

menudraw(int &selected)
{
    sclear();
    gout << move_to(XX/2, YY/2) << text("PLAY");
    gout << move_to(XX/2, (YY/2)+30) << text("EXIT");
    if(selected == 0)
    {
        gout << move_to((XX/2)+60, YY/2) << box(20,20);
    }
    if(selected == 1)
    {
        gout << move_to((XX/2)+60, (YY/2)+30) << box(20,20);
    }
}

int main()
{
    srand(time(0));
    XX = 600;
    YY = 600;
    gout.open(XX,YY);
    event ev;
    gin.timer(140);
    vector<bl> snake;
    vector<bl> kaja;
    vector<bl> wall;
    spawn(snake);
    cwall(wall);
    while(gin >> ev && ev.keycode != key_escape)
    {
        menudraw(selected);
        menu(ev);
        gout << refresh;
    }
    while(gin >> ev && ev.keycode != key_escape && gameon == true)
    {
        if(ev.type == ev_timer)
        {
            sclear();
            fspawn(kaja, wall);
            draw(snake, kaja, wall);
            feded(snake, kaja);
            smove(snake);
            crash(snake, wall);
            gout << refresh;
            c = true;
        }
            control(ev, c);
    }
    return 0;
}
