#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>

class Board {
public:
    Board(int width, int height);
    void update();
    void placePiece(const std::vector<std::vector<int>>& piece, int posX, int posY);
    void clearLines();
    void display() const;

private:
    int width, height;
    std::vector<std::vector<char>> grid;
};

#endif // BOARD_H
