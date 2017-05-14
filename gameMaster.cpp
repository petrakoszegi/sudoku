#include "gameMaster.hpp"
#include <set>

GameMaster::GameMaster(){
    gameover = false;
    this->v = new View(600,400);
}

bool GameMaster::isGameover(){
    return gameover;
}

void GameMaster::updateModel(){
        int k=0;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                matrix[i][j]=((v->getWidgets()).at(k))->getNum();
                k++;
            }
        }
        checkNumber();
        v->draw();
}

bool GameMaster::checkSudoku(){
    for (int i=0; i<9; i++){
        if (checkRow(i)==false){
            return false;
        } else if (checkCol(i)==false){
            return false;
        }
    }
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (checkBlock(i,j)==false){
                return false;
            }
        }
    }
    gameover = true;
    return true;
}

bool GameMaster::checkRow(int x){
    set<int> numbers;
    for (int i=1; i<10; i++){
        numbers.insert(i);
    }
    for (int i=0; i<9; i++){
        numbers.erase(matrix[x][i]);
    }
    return numbers.empty();
}

bool GameMaster::checkCol(int x){
    set<int> numbers;
    for (int i=1; i<10; i++){
        numbers.insert(i);
    }
    for (int i=0; i<9; i++){
        numbers.erase(matrix[i][x]);
    }
    return numbers.empty();
}

bool GameMaster::checkBlock(int x, int y){
    set<int> numbers;
    for (int i=1; i<10; i++){
        numbers.insert(i);
    }
    for (int i=3*x; i<3*x+3; i++){
        for (int j=3*y; j<3*y+3; j++){
            numbers.erase(matrix[i][j]);
        }
    }
    return numbers.empty();
}

bool GameMaster::checkNumber()
{
    set<int> actrow;
    set<int> actcol;
    set<int> actblock;
    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++)
        {
            //sorellenőrzés
            bool inrow = false;
            bool incol = false;
            bool inblock = false;
            for (int k=0; k<9; k++)
            {
                if(matrix[i][j]==matrix[i][k] && j!=k && matrix[i][j]!=0)
                {
                    inrow = true;
                    actrow.insert(matrix[i][k]);
                }
            }
            //oszlopellenőrzés
            for (int k=0; k<9; k++)
            {
                if(matrix[i][j]==matrix[k][j] && i!=k && matrix[i][j]!=0)
                {
                    incol = true;
                    actcol.insert(matrix[k][j]);
                }
            }
            for (int k=0; k<3; k++)
            {
                for (int l=0; l<3; l++)
                {
                    if(matrix[i][j]==matrix[3*(i/3)+k][3*(j/3)+l] && i!=(3*(i/3)+k) && j!=(3*(j/3)+l) && matrix[i][j]!=0)
                    {
                        inblock = true;
                        actblock.insert(matrix[3*(i/3)+k][3*(j/3)+l]);
                    }
                }
            }

            if (incol||inrow||inblock)
            {
                ((v->getWidgets()).at(9*i+j))->setWrongTrue();
            }
            else if (actrow.count(matrix[i][j])==0 && actcol.count(matrix[i][j])==0 && actblock.count(matrix[i][j])==0)
            {
                ((v->getWidgets()).at(9*i+j))->setWrongFalse();
            }

            actrow.clear();
            actcol.clear();
            actblock.clear();
        }
    }
}

