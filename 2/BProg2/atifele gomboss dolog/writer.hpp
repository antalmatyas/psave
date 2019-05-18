#ifndef WRITER_HPP_INCLUDED
#define WRITER_HPP_INCLUDED
#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <string>

class Writer : public Widget {
protected:
    bool _checked;
    double FontSize;
    std::string s;
    std::vector<std::string> boxes;

public:
    Writer(int x, int y, int sx, int sy);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void action(genv::event ev);
    virtual bool is_checked() const;
    void AddElements(std::string ae);
    void DelElements();
};

#endif // WRITER_HPP_INCLUDED


