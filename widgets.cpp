#include "widgets.hpp"
#include "graphics.hpp"

using namespace genv;

Widget::Widget(int x, int y, int sx, int sy)
{
    _x = x;
    _y = y;
    _size_x = sx;
    _size_y = sy;
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x+4 && mouse_x<_x+_size_x-4 && mouse_y>_y+4 && mouse_y<_y+_size_y-4;
}

void Widget::draw() const {
}

void Widget::handle(genv::event ev){
}

void Widget::numHandle(int d){
}

int Widget::getNum(){};

void Widget::setNum(int n){};

void Widget::setOriginalFalse(){};

void Widget::setOriginalTrue(){};

void Widget::setWrongFalse(){};

void Widget::setWrongTrue(){};
