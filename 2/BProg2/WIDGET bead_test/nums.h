#ifndef NUMS_H_INCLUDED
#define NUMS_H_INCLUDED
#include "widget.h"
#include "graphics.hpp"

#include <iostream>
#include <fstream>

class nums : public widget
{
protected:
    int val, vmin, vmax;
public:
    nums(int sx,int sy,int sw,int sh,int value,int vminimum,int vmaximum);
    virtual void draw() const;
    virtual void react(genv::event ev);
    virtual void save(std::ofstream &f) const;
};
#endif // NUMS_H_INCLUDED
