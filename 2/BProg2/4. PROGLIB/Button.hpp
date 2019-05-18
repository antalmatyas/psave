#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

class Button : public Widget
{
protected:
    std::string label;
public:
    Button(int xx, int yy, int ww, int hh, std::string vv);
    virtual void draw() const;
    virtual bool react(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
