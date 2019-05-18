#ifndef KOMPLEX_HPP_INCLUDED
#define KOMPLEX_HPP_INCLUDED

class komplex
{
    double ima, rea;
public:
    double re()
    {
        return rea;
    }
    double im()
    {
        return ima;
    }
    komplex(double a, double b)
    {
        rea = a;
        ima = b;
    }
    komplex operator*(komplex k)
    {
        double re = (rea * k.rea) - (ima * k.ima);
        double img = (rea * k.ima) + (rea * k.ima);
        komplex e(re, img);
        return e;
    }
    komplex operator+(komplex k)
    {
        double re = (rea + k.rea);
        double img = (ima + k.ima);
        komplex e(re, img);
        return e;
    }
};



#endif // KOMPLEX_HPP_INCLUDED
