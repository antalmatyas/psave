#ifndef STEXT_HPP_INCLUDED
#define STEXT_HPP_INCLUDED

class SText : public Widget
{
protected:
    std::string vstring;
public:
    SText(int xx, int yy, int ww, int hh, std::string vv);
    virtual void draw() const;
    //virtual void save(std::ofstream &f) const;
};

#endif // STEXT_HPP_INCLUDED
