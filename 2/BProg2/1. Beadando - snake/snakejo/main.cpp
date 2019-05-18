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
bool gov = false;
bool c = true;

    string pl = "PLAY";
    string ex = "EXIT";
    string go = "GAME OVER";

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

void fspawn(vector<bl> &kaja, vector<bl> &wall, vector<bl> &snake)
{
    while(1){
        if(kaja.size() == 0)
        {
            bl a;
            a.x = s*(rand() % (XX/s));
            a.y = s*(rand() % (YY/s));
            cout << a.x << ":" << a.y << endl;
            bool indawall = false;
            for(int i = 0 ; i < wall.size() ; i++)
            {
                if(wall[i].x == a.x && wall[i].y == a.y)
                {
                    indawall = true;
                }
                if(i<snake.size())
                {
                    if(snake[i].x == a.x && snake[i].y == a.y)
                    {
                        indawall = true;
                    }
                }
            }
            if(indawall == false)
            {
                kaja.push_back(a);
                return;
            }
        }
        else{return;}
    }
}

void feded(vector<bl> &snake, vector<bl> &kaja)
{
    if(snake[0].x == kaja[0].x && snake[0].y == kaja[0].y)
    {
        kaja.pop_back();
        bl a;
        a.x = snake[snake.size()-1].x;
        a.y = snake[snake.size()-1].y;
        snake.push_back(a);
        score++;
    }
}

void gameover(event &ev)
{
    gout << color(200, 0, 0) << move_to((XX/2)-(gout.twidth(go)/2), YY/3) << text(go);
    gout << color(255,255,255) << move_to( XX/2-(gout.twidth(ex)/2), YY/2 ) << text(ex);
}

void crash(vector<bl> &snake, vector<bl> &wall, bool &gov)
{
    for(int i = 1 ; i < snake.size() ; i++)
    {
        for(int j  = 0 ; j < wall.size() ; j++)
        {
           if((snake[0].x == snake[i].x && snake[0].y == snake[i].y) || (snake[0].x == wall[j].x && snake[0].y == wall[j].y) )
            {
                gov = true;
                return;
            }
        }
    }
}

void cwall(vector<bl> &wall)
{
    for(int i = 0 ; i <= (XX-20)/20 ; i++)
    {
        bl a;
        a.y = 0;
        a.x = 20*i;
        wall.push_back(a);
    }
    for(int i = 0 ; i <= (XX-20)/20 ; i++)
    {
        bl a;
        a.y = YY-20;
        a.x = 20*i;
        wall.push_back(a);
    }
    for(int i = (YY/3) ; i <= 2*(YY/3) ; i++)
    {
        bl a;
        a.y = i;
        a.x = (XX/3);
        wall.push_back(a);
    }
}

void menudraw()
{
    gout << color(255,255,255) << move_to( XX/2-(gout.twidth(pl)/2), YY/3 ) << text(pl);
    gout << move_to( XX/2-(gout.twidth(ex)/2), YY/2 ) << text(ex);
}

int menuctrl(event &ev)
{
    if(ev.button == btn_left)
    {
        if(ev.pos_y <= YY/3 && ev.pos_y >= (YY/3)-gout.cascent() && ev.pos_x > (XX/2-(gout.twidth(pl)/2)) && ev.pos_x < (XX/2+(gout.twidth(pl)/2)))
        {
            return 1;
        }
        else if(ev.pos_y <= YY/2 && ev.pos_y >= (YY/2)-gout.cascent() && ev.pos_x > (XX/2-(gout.twidth(ex)/2)) && ev.pos_x < (XX/2+(gout.twidth(ex)/2)))
        {
            return 2;
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
    gin.timer(140);
    vector<bl> snake;
    vector<bl> kaja;
    vector<bl> wall;
    cwall(wall);
    while(1)
    {
        sclear();
        gov = false;
        while(gin >> ev)
        {
            menudraw();
            if(menuctrl(ev) == 1)
            {
                spawn(snake);
                break;
            }
            else if(menuctrl(ev) == 2 || ev.keycode == key_escape)
            {
                exit(0);
            }

            gout << refresh;
        }
        while(gin >> ev && !gov)
        {
            if(ev.type == ev_timer)
            {
                sclear();
                fspawn(kaja, wall, snake);
                draw(snake, kaja, wall);
                feded(snake, kaja);
                smove(snake);
                crash(snake, wall, gov);
                gout << refresh;
                c = true;
            }
            if(ev.keycode == key_escape)
            {
                exit(0);
            }
                control(ev, c);
        }
        while(gin >> ev)
        {
            gout << move_to(XX/2, YY/2) << text("GAME OVER  Score: ") << text(sc);
            gout << move_to(XX/2, (YY/2)+30) << text("Press ENTER to return to the menu");
            gout << refresh;
            for(int i = 0 ; i < snake.size() ; i++)
            {
                snake.pop_back();
            }
            if(ev.keycode == key_enter)
            {
                break;
            }
            if(ev.keycode == key_escape)
            {
                exit(0);
            }
        }
    }
    return 0;
}
