#include "graphics.hpp"
#include "Widget.hpp"

using namespace std;
using namespace genv;


Widget :: Widget(int xx, int yy, int ww, int hh)
{
    x = xx;
    y = yy;
    h = hh;
    w = ww;
}
void Widget :: draw() const{}
