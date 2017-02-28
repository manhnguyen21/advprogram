#ifndef GAMEGROUND_H
#define GAMEGROUND_H

#include <vector>
#include "Snake.h"
#include "Position.h"

enum CellType {
    CELL_EMPTY = 0, CELL_SNAKE, CELL_CHERRY
};

enum GameStatus {
    GAME_RUNNING = 1,
    GAME_STOP = 2,
    GAME_WON = 4 | GAME_STOP,
    GAME_LOST = 8 | GAME_STOP,
};

class PlayGround
{
    std::vector< std::vector<CellType> > squares;
    Snake snake;
    GameStatus status;
    int score;
public:
    PlayGround(int width, int height);
    ~PlayGround();

    bool isGameRunning() const { return status == GAME_RUNNING; }
    void processUserInput(UserInput input);
    void nextStep();
    void changeCellState(Position pos, CellType type);
    void addCherry() { squares[0][0] = CELL_CHERRY; }

    int getWidth() const { return squares[0].size(); }
    int getHeight() const { return squares.size(); }
    const std::vector< std::vector<CellType> >& getSquares() const { return squares; }
};

#endif // GAMEGROUND_H
