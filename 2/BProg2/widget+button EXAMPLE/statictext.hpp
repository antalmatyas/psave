#ifndef STATICTEXT_HPP_INCLUDED
#define STATICTEXT_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class StaticText : public Widget {
protected:
    std::string _s;
public:
    StaticText(int x, int y, int sx, int sy, std::string s);
    virtual void draw() const ;
    virtual bool focusable() const {return false;}
    void setText(std::string s) {_s=s;}
};


#endif // STATICTEXT_HPP_INCLUDED
