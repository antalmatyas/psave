#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "graphics.hpp"
#include "Widget.hpp"

using namespace std;

class Button : public Widget
{
protected:
    std::string out;
public:
    Button(int xx, int yy, int ww, int hh, string s);
    virtual void draw() const;
    virtual bool active(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
