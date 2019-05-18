#include "graphics.hpp"
#include <iostream>
using namespace genv;
using namespace std;


int main()
{
    string s;
    cin >> s;
    if(s == "start"){
    gout.open(600,600);
    //gout <<text("hello world")<< refresh;
    event ev;
    gout << color(255,0,0) << line(0,-300) << refresh;
    gout << line(0, 600) << refresh;
    gout << move_to(300, 300) << line(300, 0) << refresh;
    gout << line(-600, 0) << refresh;
    int r = 0;
    for(int i = 10 ; i <= 300 ; i=i+10)
    {
        gout << color(r, 0, 255-r);
        gout << move_to(300+i,300) << line_to(300, 0+i) << refresh;
        r = r+8;
    }

    r = 0;
    for(int i = 10 ; i <= 300 ; i=i+10)
    {
        gout << color(r, 0, 255-r);
        gout << move_to(300,300+i) << line_to(600-i, 300) << refresh;
        r = r+8;
    }

    r = 0;
    for(int i = 10 ; i <= 300 ; i=i+10)
    {
        gout << color(r, 0, 255-r);
        gout << move_to(300-i,300) << line_to(300, 600-i) << refresh;
        r = r+8;
    }

    r = 0;
    for(int i = 10 ; i <= 300 ; i=i+10)
    {
        gout << color(r, 0, 255-r);
        gout << move_to(300,300-i) << line_to(0+i, 300) << refresh;
        r = r+8;
    }
    while(gin >> ev) {
    }
    return 0;
    }
}
