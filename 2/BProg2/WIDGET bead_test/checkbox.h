#ifndef CHECKBOX_H_INCLUDED
#define CHECKBOX_H_INCLUDED

#include "widget.h"
#include "graphics.hpp"

#include <iostream>
#include <fstream>
#include <vector>

class checkbox : public widget
{
protected:
    int quantity;
    std::vector<bool> checked;
    //std::vector<string> id;
public:
    checkbox(int sx,int sy,int sw,int sh, int q);
    virtual void draw() const;
    //virtual void react(genv::event ev);
    //virtual void save(std::ofstream &f) const;
};

#endif // CHECKBOX_H_INCLUDED
