#include "view.hpp"
#include "numDisplay.hpp"
#include "button.hpp"

using namespace genv;

View::View(int x, int y){
    gout.open(x,y);
    addWidgets(this->widgets);
    addButtons(this->buttons);
    escape = false;
}

void View::draw(){
    event ev;
    gin>>ev;
    event_loop(this->widgets, this->buttons, ev);
        for(int j=50; j<=320; j+=3){
            for(int k=50; k<=320; k+=90){
                gout<<move_to(j,k)<<color(255,255,255);
                gout<<box(3,3);
                gout<<move_to(k,j);
                gout<<box(3,3);
            }
        }
        gout<<refresh;
}

void View::event_loop(vector<Widget*>& widgets, vector<button*>& buttons, event ev) {
    for (int i=0;i<buttons.size();i++) {
        buttons[i]->handle(ev);
        buttons[i]->draw();
    }
    for (int i=0;i<widgets.size();i++) {
        widgets[i]->handle(ev);
        widgets[i]->draw();
    }
    if(ev.keycode==key_escape){
        escape = true;
    }
}

void View::addWidgets(vector<Widget*>& widgets){
    int x = 50;
    int y = 50;
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            numDisplay* nd = new numDisplay(x,y,30,30);
            nd->setHighest(9);
            nd->setLowest(0);
            widgets.push_back(nd);
            x+=30;
        }
        x=50;
        y+=30;
    }
}

void View::addButtons(vector<button*>& buttons){
    button* b0 = new button(370,50,150,40);
    b0->setText("Easy");
    buttons.push_back(b0);
    button* b1 = new button(370,100,150,40);
    b1->setText("Medium");
    buttons.push_back(b1);
    button* b2 = new button(370,150,150,40);
    b2->setText("Hard");
    buttons.push_back(b2);
    button* b3 = new button(370,283,150,40);
    b3->setText("Exit");
    buttons.push_back(b3);

    for(int i=0;i<buttons.size();i++){
            buttons[i]->all=buttons;
    }
}

vector<Widget*> View::getWidgets(){
    return this->widgets;
}

void View::drawGameover(){
    while(escape==false){
        gout<<move_to(0,0)<<color(0,0,0);
        gout<<box(600,400);
        gout<<move_to(380,200);
        gout<<color(255,255,255)<<text("YOU WIN!");
    }
}
