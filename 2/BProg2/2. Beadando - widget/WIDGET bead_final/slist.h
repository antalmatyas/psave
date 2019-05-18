#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include "widget.h"
#include "graphics.hpp"

class slist : public widget
{
protected:
    std::vector<std::string> lista;
    size_t aktuell;
    int oph;
public:
    slist(int sx,int sy,int sw,int sh, int nh, std::vector<std::string> value, size_t ak);
    virtual void draw() const;
    virtual void react(genv::event ev);
    virtual void newobj(std::string a);
    virtual void save(std::ofstream &f) const;
};

#endif // SLIST_H_INCLUDED
