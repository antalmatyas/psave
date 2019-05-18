#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED
#include "graphics.hpp"
#include <vector>

class widget
{
protected:
    int x, y, w, h;
public:
    virtual bool selected(int mx, int my) const;
    virtual void draw() const;
    virtual void react(genv::event ev) {};
};


#endif // WIDGET_H_INCLUDED
