#include <iostream>
#include <sstream>
#include <string>
#include "widgets.hpp"
#include "graphics.hpp"
#include "button.hpp"
#include "gameMaster.hpp"

button::button(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    selected = false;
}

void button::setText(string s){
    t = s;
}

void button::handle(genv::event ev){
     if(ev.type==ev_mouse && ev.button==btn_left && is_selected(ev.pos_x, ev.pos_y)){
        for(int i=0;i<all.size();i++)
            all[i]->selected=false;
        selected = true;
    }

}

void button::draw() const{
    if(selected){
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y);
        gout<<move_to(_x+3,_y+3)<<color(150,210,180)<<box(_size_x-6,_size_y-6);
        gout<<move_to(_x+_size_x/2-t.length()*4,_y+_size_y/2+3)<<color(255,255,255)<<text(t);
    }else{
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y);
        gout<<move_to(_x+3,_y+3)<<color(0,0,0)<<box(_size_x-6,_size_y-6);
        gout<<move_to(_x+_size_x/2-t.length()*4,_y+_size_y/2+3)<<color(255,255,255)<<text(t);
    }
}
