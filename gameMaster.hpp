#ifndef GAMEMASTER_HPP_INCLUDED
#define GAMEMASTER_HPP_INCLUDED
#include "view.hpp"

class GameMaster{
protected:
    bool gameover;
    int matrix[9][9];

public:
    View* v;
    GameMaster();
    bool isGameover();
    void updateModel();
    bool checkSudoku();
    bool checkRow(int x);
    bool checkCol(int x);
    bool checkBlock(int x, int y);
    bool checkNumber();
};

#endif // GAMEMASTER_HPP_INCLUDED
