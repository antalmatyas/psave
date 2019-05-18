#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"

class Textbox : public Widget {
protected:
    bool _checked;
    double FontSize;
    std::string s;

public:
    Textbox(int x, int y, int sx, int sy);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void action(genv::event ev);
    virtual bool is_checked() const;
    std::string _getText();
};

#endif // TEXTBOX_HPP_INCLUDED

