#ifndef SINPUT_H_INCLUDED
#define SINPUT_H_INCLUDED

#include "graphics.hpp"
#include "widget.h"

class sinput : public widget
{
protected:
    std::string texts;
public:
    sinput(int sx,int sy,int sw,int sh);
    virtual void draw() const;
    virtual void react(genv::event ev);
    virtual void save(std::ofstream &f) const;
};

#endif // SINPUT_H_INCLUDED
