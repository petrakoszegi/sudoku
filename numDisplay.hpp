#ifndef NUMDISPLAY_HPP_INCLUDED
#define NUMDISPLAY_HPP_INCLUDED
#include <iostream>

using namespace genv;
using namespace std;

#include "widgets.hpp"

class numDisplay : public Widget {
protected:
    int num;
    int lowest;
    int highest;
    bool original;
    bool wrong;
public:
    numDisplay(int x, int y, int sx, int sy);
    virtual void draw() const;
    virtual void handle(genv::event ev);
    virtual void numHandle(int d);
    int getNum();
    void setNum(int n);
    void setLowest(int l);
    void setHighest(int h);
    void setOriginalFalse();
    void setOriginalTrue();
    void setWrongFalse();
    void setWrongTrue();
};

#endif
