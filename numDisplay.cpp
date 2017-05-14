#include <iostream>
#include <sstream>
#include "widgets.hpp"
#include "graphics.hpp"
#include "numDisplay.hpp"
#include "gameMaster.hpp"


using namespace genv;
using namespace std;

numDisplay::numDisplay(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    num=0;
    lowest=0;
    highest=0;
    wrong=false;
}

void numDisplay::draw() const {
    stringstream ss;
    ss<<num;
    if (num==0){
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y)<<move_to(_x+1,_y+1)<<color(0,0,0)<<box(_size_x-2,_size_y-2);
    } else if (original){
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y)<<move_to(_x+1,_y+1)<<color(0,0,0)<<box(_size_x-2,_size_y-2);
        gout<<move_to((_x+_size_x/2-4),(_y+_size_y/2+4))<<color(0,255,0)<<text(ss.str());
    } else if (wrong) {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y)<<move_to(_x+1,_y+1)<<color(0,0,0)<<box(_size_x-2,_size_y-2);
        gout<<move_to((_x+_size_x/2-4),(_y+_size_y/2+4))<<color(255,0,0)<<text(ss.str());
    } else {
        gout<<move_to(_x,_y)<<color(255,255,255)<<box(_size_x,_size_y)<<move_to(_x+1,_y+1)<<color(0,0,0)<<box(_size_x-2,_size_y-2);
        gout<<move_to((_x+_size_x/2-4),(_y+_size_y/2+4))<<color(255,255,255)<<text(ss.str());
    }
}

void numDisplay::handle(genv::event ev){
        if(is_selected(ev.pos_x,ev.pos_y)&&ev.button==btn_wheelup){
            numHandle(1);
        } else if(is_selected(ev.pos_x,ev.pos_y)&&ev.button==btn_wheeldown){
            numHandle(-1);
        }
}

void numDisplay::setLowest(int l){
    lowest = l;
}

void numDisplay::setHighest(int h){
    highest = h;
}

void numDisplay::numHandle(int d){

    if((num+d)<=highest && (num+d)>=lowest && !original){
        num+=d;
    }
}

int numDisplay::getNum(){
    return this->num;
}

void numDisplay::setNum(int n){
    this->num = n;
}

void numDisplay::setOriginalTrue(){
    original = true;
}

void numDisplay::setOriginalFalse(){
    original = false;
}

void numDisplay::setWrongTrue(){
    wrong = true;
}

void numDisplay::setWrongFalse(){
    wrong = false;
}
