#ifndef KOMPLEX_HPP_INCLUDED
#define KOMPLEX_HPP_INCLUDED

class komplex
{
public:
    double ima, rea;
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
};

komplex operator*(komplex a, const komplex& b); // ómeghirdetve, h mindenhol lehessen használni
//amugy multiple operation declaration, v mi
komplex operator+(const komplex& a, const komplex& b);
#endif // KOMPLEX_HPP_INCLUDED
