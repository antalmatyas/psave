#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>

class Widget
{
protected:
    int x, y, w, h;
public:
    Widget(int xx, int yy, int ww, int hh);
    virtual bool selected(int mx, int my) const;
    virtual void draw() const;
    virtual void react(genv::event ev) {};
};


#endif // WIDGET_HPP_INCLUDED
