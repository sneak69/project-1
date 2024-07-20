#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "TicTacToe.h"
#include <string>
#include <deque>
#include <utility>
#include <unordered_map>

class GameLogic : public TicTacToe {
private:
    struct Player {
        std::string name;
        char symbol;
        int wins;
    };

    Player player1;
    Player player2;
    Player* currentPlayer;
    std::string statsFilename;
    std::deque<std::pair<std::string, int>> highestScores;
    std::string highestScoreFilename;

public:
    GameLogic();
    ~GameLogic();
    void mainMenu();

private:
    void playGame();
    void getPlayerMove(int& row, int& col);
    void setInitialTurn();
    void switchTurn();
    void getPlayerNames();
    void displayStatistics();
    bool askForRematch();
    void displayFinalStatistics();
    void resetScores();
    void savePlayerStatistics();
    bool loadPlayerStatistics();
    void clearGameHistory();
    void updateHighestScores();
    void loadHighestScores();
    void saveHighestScores();
    void clearHighestScores();
    void displayHighestScores() const;
};

#endif // GAMELOGIC_H
