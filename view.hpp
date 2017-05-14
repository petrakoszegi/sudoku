#ifndef VIEW_HPP_INCLUDED
#define VIEW_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include "button.hpp"
#include <vector>

class View{
protected:
    int width;
    int height;
    bool escape;
    vector<Widget*> widgets;
public:
    vector<button*> buttons;
    View(int x, int y);
    void draw();
    void event_loop(vector<Widget*>& widgets, vector<button*>& buttons, event ev);
    void addWidgets(vector<Widget*>& widgets);
    void addButtons(vector<button*>& buttons);
    void drawGameover();
    vector<Widget*> getWidgets();
};


#endif // VIEW_HPP_INCLUDED
