#include "graphics.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "Thingy.hpp"
#include "DungeonMaster.hpp"
#include <vector>
#include <iostream>

using namespace std;
using namespace genv;

DungeonMaster :: DungeonMaster()
{
    player = true;

//  true -> kék
//  false -> piros

    ingame = true;
    round = 0;
}

void DungeonMaster :: check(vector<vector<Thingy*>> &dolgok)
{
    for(int i = 4 ; i < 20 ; i++)
    {
        for(int j = 0 ; j < 16 ; j++)
        {
            if(dolgok[i][j]->gtype() != 0 )
            {
                if(dolgok[i][j]->gtype() == dolgok[i-1][j+1]->gtype() && dolgok[i][j]->gtype() == dolgok[i-2][j+2]->gtype() && dolgok[i][j]->gtype() == dolgok[i-3][j+3]->gtype() && dolgok[i][j]->gtype() == dolgok[i-4][j+4]->gtype())
                {
                    ingame = false;
                    return;
                }
            }
        }
    }

    for(int i = 0 ; i < 16 ; i++)
    {
        for(int j = 0 ; j < 16 ; j++)
        {
            if(dolgok[i][j]->gtype() != 0 )
            {
                if(dolgok[i][j]->gtype() == dolgok[i+1][j+1]->gtype() && dolgok[i][j]->gtype() == dolgok[i+2][j+2]->gtype() && dolgok[i][j]->gtype() == dolgok[i+3][j+3]->gtype() && dolgok[i][j]->gtype() == dolgok[i+4][j+4]->gtype())
                {
                    ingame = false;
                    return;
                }
            }
        }
    }



    for(int i = 0 ; i < 17 ; i++)
    {
        for(int j = 0 ; j < 17 ; j++)
        {
            if(dolgok[i][j]->gtype() != 0 )
            {
                if(dolgok[i][j]->gtype() == dolgok[i][j+1]->gtype() && dolgok[i][j]->gtype() == dolgok[i][j+2]->gtype() && dolgok[i][j]->gtype() == dolgok[i][j+3]->gtype() && dolgok[i][j]->gtype() == dolgok[i][j+4]->gtype())
                {
                    ingame = false;
                    return;
                }
            }
            if(dolgok[i][j]->gtype() != 0)
            {
                if(dolgok[i][j]->gtype() == dolgok[i+1][j]->gtype() && dolgok[i][j]->gtype() == dolgok[i+2][j]->gtype() && dolgok[i][j]->gtype() == dolgok[i+3][j]->gtype() && dolgok[i][j]->gtype() == dolgok[i+4][j]->gtype())
                {
                    ingame = false;
                    return;
                }
            }
        }
    }
}

void DungeonMaster :: tick(int xx, int yy, vector<vector<Thingy*>> &dolgok)
{
    int a = (xx/30)-1;
    int b = (yy/30)-1;
    if(dolgok[a][b]->emp())
    {
        if(player)
        {
            dolgok[a][b]->cht2();
            player = !player;
            round++;
            check(dolgok);
        }
        else
        {
            dolgok[a][b]->cht1();
            player = !player;
            round++;
            check(dolgok);
        }
    }
}

void DungeonMaster :: sclear()
{
    gout << move_to(0, 0) << color(0, 0, 0) << box(900, 700);
    gout << refresh;
}

void DungeonMaster :: eventLoop()
{
    gout.open(900,700);
    event ev;
    bool esc = false;
    vector<vector<Thingy*>> dolgok;
    string s = "START";
    Button *start = new Button(410, 320, 80, 60, s);

    for(int i = 0 ; i < 20 ; i++)
    {
        vector<Thingy*> id;
        for(int j = 0 ; j < 20 ; j++)
        {
            Thingy *cucc = new Thingy((i+1)*30, (j+1)*30, 30, 30);
            id.push_back(cucc);
        }
        dolgok.push_back(id);
    }
    start->draw();
    gout << refresh;
    while(!esc)
    {
        while(gin >> ev)
        {
            if(ev.button == btn_left)
            {
                if(start->active(ev))
                {
                    ingame = true;
                    break;
                }
            }
            if(ev.keycode == key_escape)
            {
                esc = true;
                break;
            }
        }
        sclear();
        while(gin >> ev && ingame == true && !esc)
        {
            for(int i = 0 ; i < 20 ; i++)
            {
                for(int j = 0 ; j < 20 ; j++)
                {
                    dolgok[i][j]->draw();
                }
            }
            if(ev.button == btn_left && ev.pos_x > 30 && ev.pos_x < 630 && ev.pos_y > 30 && ev.pos_y < 630)
            {
                tick(ev.pos_x, ev.pos_y, dolgok);
            }
            gout << move_to(750, 40) << color(255, 255, 255) << text("Next:");
            gout << move_to(800, 20);
            if(player)
            {
                gout << color(0, 0, 255) << box(30, 30);
            }
            else
            {
                gout << color(255, 0, 0) << box(30, 30);
            }
            gout << refresh;

            if(ev.keycode == key_escape)
            {
                esc = true;
                break;
            }
            if(round == 400)
            {
                break;
            }
        }
        sclear();
        while(gin >> ev)
        {
            if(round == 400)
            {
                gout << move_to(450, 350) << color(255, 255, 255) << text("IT'S A TIE");
            }
            else if(player == true)
            {
                gout << move_to(450, 350) << color(255, 0, 0) << text("RED WON");
            }
            else if(player == false)
            {
                gout << move_to(450, 350) << color(0, 0, 255) << text("BLUE WON");
            }

            gout << move_to(20, 680) << color(255, 255, 255) << text("Press 'Escape' to exit");
            gout << refresh;
            if(ev.keycode == key_escape)
            {
                esc = true;
                break;
            }
        }
    }
    return;
}


