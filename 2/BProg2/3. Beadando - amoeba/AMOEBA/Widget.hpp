#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

class Widget
{
protected:
    int x;
    int y;
    int h;
    int w;
public:
    Widget(int xx, int yy, int ww, int hh);
    virtual void draw() const;
};

#endif // WIDGET_HPP_INCLUDED
