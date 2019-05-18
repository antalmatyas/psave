#include "graphics.hpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "komplex.hpp"
using namespace genv;
using namespace std;

const int XX=800;
const int YY=600;


const int MAX = 255;

int main()
{
    gout.open(XX,YY);
    for (int x=0;x<XX;x++) {
        for (int y=0;y<YY;y++) {
            double cr = (4.0/double(XX))*x - 2.0;
            double ci = (4.0/double(YY))*y - 2.0;
            komplex c(cr, ci);
            komplex z(0,0);
            int t = 0;
            while (z.re()*z.re()+z.im()*z.im() < 4.0 && t < MAX) {
                z = z*z+c;
                ++t;
            }
            t=t*15;
            gout << move_to(x,y) << color(t,t,t) << dot;
        }
    gout << refresh;
    }
    event ev;
    while(gin >> ev && ev.keycode != key_escape) {
    }
    return 0;
}
