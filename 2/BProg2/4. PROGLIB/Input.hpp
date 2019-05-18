#ifndef INPUT_HPP_INCLUDED
#define INPUT_HPP_INCLUDED

class Input : public Widget
{
protected:
    std::string value;
public:
    Input(int xx, int yy, int ww, int hh);
    virtual void draw() const;
    virtual void react(genv::event ev);
};

#endif // INPUT_HPP_INCLUDED
