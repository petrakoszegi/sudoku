#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "widgets.hpp"

class button : public Widget {
protected:
    string t;
public:
    bool selected;
    button(int x, int y, int sx, int sy);
    vector<button*> all;
    virtual void handle(genv::event ev);
    virtual void draw() const;
    void setText(string s);
};
#endif // BUTTON_HPP_INCLUDED
