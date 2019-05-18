#ifndef TEXTEDITOR_HPP_INCLUDED
#define TEXTEDITOR_HPP_INCLUDED
#include <string>
#include "widgets.hpp"

class TextEditor : public Widget{
    std::string _s;
public:
    TextEditor(int x, int y, int sx, int sy, std::string s);
    virtual bool focusable() const {return true;}
    virtual void draw() const ;
    virtual void handle(genv::event ev) ;
    inline std::string value() {return _s;}
};



#endif // TEXTEDITOR_HPP_INCLUDED
