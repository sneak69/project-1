#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>
#include <string>
#include <algorithm>

class TicTacToe {
protected:
    char arr[3][3];

public:
    TicTacToe();
    void fillBoard();
    void displayBoard() const;
    bool isFilled(int row, int col) const;
    void change(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool checkDraw() const;

private:
    bool winGameRow(char symbol) const;
    bool winGameCol(char symbol) const;
    bool winGameDiag1(char symbol) const;
    bool winGameDiag2(char symbol) const;
};

#endif // TICTACTOE_H
