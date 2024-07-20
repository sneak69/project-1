#include "TicTacToe.h"

using namespace std;

TicTacToe::TicTacToe() {
    fillBoard();
}

void TicTacToe::fillBoard() {
    for (auto& row : arr) {
        fill(begin(row), end(row), '-');
    }
}

void TicTacToe::displayBoard() const {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << arr[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------\n";
    }
}

bool TicTacToe::isFilled(int row, int col) const {
    return (arr[row][col] == 'X' || arr[row][col] == 'O');
}

void TicTacToe::change(int row, int col, char symbol) {
    arr[row][col] = symbol;
}

bool TicTacToe::checkWin(char symbol) const {
    return (winGameRow(symbol) || winGameCol(symbol) || winGameDiag1(symbol) || winGameDiag2(symbol));
}

bool TicTacToe::checkDraw() const {
    for (const auto& row : arr) {
        if (any_of(begin(row), end(row), [](char c) { return c == '-'; })) {
            return false;
        }
    }
    return true;
}

bool TicTacToe::winGameRow(char symbol) const {
    for (const auto& row : arr) {
        if (all_of(begin(row), end(row), [symbol](char c) { return c == symbol; })) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::winGameCol(char symbol) const {
    for (int col = 0; col < 3; ++col) {
        if (all_of(begin(arr), end(arr), [col, symbol](const auto& row) { return row[col] == symbol; })) {
            return true;
        }
    }
    return false;
}

bool TicTacToe::winGameDiag1(char symbol) const {
    return (arr[0][0] == symbol && arr[1][1] == symbol && arr[2][2] == symbol);
}

bool TicTacToe::winGameDiag2(char symbol) const {
    return (arr[0][2] == symbol && arr[1][1] == symbol && arr[2][0] == symbol);
}
