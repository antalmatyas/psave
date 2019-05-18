#ifndef NUMS_HPP_INCLUDED
#define NUMS_HPP_INCLUDED

class Nums : public Widget
{
protected:
    int val, vmin, vmax;
public:
    Nums(int xx, int yy, int ww, int hh, int value, int minimum, int maximum);
    virtual void draw() const;
    virtual void react(genv::event ev);
    //virtual void save(std::ofstream &f) const;
};


#endif // NUMS_HPP_INCLUDED
