#include "writer.hpp"
#include "graphics.hpp"

using namespace genv;
using namespace std;

Writer::Writer(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked=false;
    FontSize = 15;
}

void Writer::draw() const
{
    gout << move_to(_x, _y) << color(255,255,255) << box(_size_x, _size_y);
    gout << move_to(_x+2, _y+2) << color(0,0,0) << box(_size_x-4, _size_y-4);

    gout << color(255,255,255);

    gout.load_font("LiberationsSans-Regular.ttf", FontSize);
    /*gout << move_to(_x+3,_y+16);

    gout << text("ABLAK");*/
    int c = 16;
    if(boxes.size() <= 12)
    {
    for (int i=1; i<boxes.size()+1; i++)
    {
        gout << move_to(_x+3,_y+c*i) << text(boxes[i-1]);
    }
    }
    if(boxes.size() >= 12)
    {
        for (int i=1; i<=12; i++)
        {
        gout << move_to(_x+3,_y+c*i) << text(boxes[i-1]);
        }
    }
}
void Writer::DelElements()
{
    if(boxes.size() > 0)
    {
        boxes.pop_back();
    }
}

void Writer::AddElements(std::string ae)
{
    boxes.push_back(ae);
}

void Writer::handle(event ev)
{
}

bool Writer::is_checked() const
{
    return _checked;
}

void Writer::action(event ev)
{
}
