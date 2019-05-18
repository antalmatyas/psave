#include "komplex.hpp"

komplex operator*(komplex a, const komplex& b)
    {
        double re = (a.rea * b.rea) - (a.ima * b.ima);
        double img = (a.rea * b.ima) + (a.rea * b.ima);
        komplex e(re, img);
        return e;
    }
    komplex operator+(const komplex& a, const komplex& b)
    {
        double re = (a.rea + b.rea);
        double img = (a.ima + b.ima);
        komplex e(re, img);
        return e;
    }

