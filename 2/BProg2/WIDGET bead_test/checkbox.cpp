#include <stdio.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "slist.h"
#include "widget.h"
#include "graphics.hpp"
#include "checkbox.h"

using namespace std;
using namespace genv;

checkbox :: checkbox(int sx,int sy,int sw,int sh, int q)
{
    x = sx;
    y = sy;
    w = sw;
    h = sh;
    quantity = q;
    for(int i = 0 ; i < quantity ; i++)
    {
        checked[i]=false;
    }
}

void checkbox :: draw() const
{

}
