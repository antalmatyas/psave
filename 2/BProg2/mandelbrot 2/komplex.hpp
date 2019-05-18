#ifndef KOMPLEX_HPP_INCLUDED
#define KOMPLEX_HPP_INCLUDED

class komplex
{
    public:
    double real;
    double imaginary;
    double re()
    {
        return real;
    }
    double im()
    {
        return imaginary;
    }
    komplex(double a, double b)
    {
        real = a;
        imaginary = b;
    }
    komplex operator*(komplex k)
    {
        double r = (real * k.real) - (imaginary * k.imaginary);
        double i = (real * k.imaginary) + (real * k.imaginary);
        komplex e(r, i);
        return e;
    }
    komplex operator+(komplex k)
    {
        double r = (real + k.real);
        double i = (imaginary + k.imaginary);
        komplex e(r, i);
        return e;
    }
};


#endif // KOMPLEX_HPP_INCLUDED
