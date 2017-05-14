#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED
#include <vector>
#include <iostream>

#include "graphics.hpp"

using namespace genv;
using namespace std;


class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    //int dir;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void numHandle(int d);
    virtual int getNum();
    virtual void setNum(int n);
    virtual void setOriginalFalse();
    virtual void setOriginalTrue();
    virtual void setWrongFalse();
    virtual void setWrongTrue();
};

#endif
