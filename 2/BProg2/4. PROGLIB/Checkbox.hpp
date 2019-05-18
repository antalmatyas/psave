#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED

class Checkbox : public Widget
{
protected:
    bool checked;
public:
    Checkbox(int xx, int yy, int ww, int hh);
    virtual void draw() const;
    virtual void react(genv::event ev);
};

#endif // CHECKBOX_HPP_INCLUDED
