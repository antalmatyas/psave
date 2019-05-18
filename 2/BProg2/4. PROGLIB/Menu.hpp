#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

class Menu : public Widget
{
protected:
    std::vector<std::string> elements;
    size_t aktuell;
    int oph;
public:
    Menu(int xx, int yy, int ww, int hh, int oh, std::vector<std::string> value, size_t ak);
    virtual void draw() const;
    virtual void react(genv::event ev);
};

#endif // MENU_HPP_INCLUDED
