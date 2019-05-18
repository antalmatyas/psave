#ifndef THINGY_HPP_INCLUDED
#define THINGY_HPP_INCLUDED


class Thingy : public Widget
{
protected:
    int type;
public:
    Thingy(int xx, int yy, int ww, int hh);
    virtual void draw() const;
    virtual void react(genv::event ev) {}
    virtual void cht1();
    virtual void cht2();
    virtual bool emp();
    virtual int gtype();
};


#endif // THINGY_HPP_INCLUDED
