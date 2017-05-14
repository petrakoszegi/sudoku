#include "view.hpp"
#include "gameMaster.hpp"
#include <iostream>
#include <fstream>

using namespace genv;

void input(GameMaster gm);

int main()
{
    GameMaster gm = GameMaster();
    input(gm);
    while ((gm.isGameover()==false) && (gm.v->buttons[3]->selected==false)){
        input(gm);
        gm.updateModel();
        gm.checkSudoku();
    }
    //gm.v->drawGameover();

    return 0;
}

void input(GameMaster gm){
    fstream file("ures");
    if(gm.v->buttons[0]->selected){
        gm.v->buttons[0]->selected =false;
        file.open("konnyu.txt");
    }else if(gm.v->buttons[1]->selected){
        gm.v->buttons[1]->selected =false;
        file.open("kozepes.txt");
    }else if (gm.v->buttons[2]->selected){
        gm.v->buttons[2]->selected =false;
        file.open("nehez.txt");
    }
    int a;
    int k=0;
    while (file>>a){
        ((gm.v->getWidgets()).at(k))->setNum(a);
        if (a!=0){
            ((gm.v->getWidgets()).at(k))->setOriginalTrue();
        }else{
            ((gm.v->getWidgets()).at(k))->setOriginalFalse();
        }
        k++;
    }
}

