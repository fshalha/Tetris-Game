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
    bool isRowFull(int row); void shiftDownRowsAbove(int clearedRow);
    void clearRow(int row);
bool canMoveDown(const std::vector<std::vector<int>>& piece, int posX, int posY);
bool canMoveLeft(const std::vector<std::vector<int>>& piece, int posX, int posY);
bool canMoveRight(const std::vector<std::vector<int>>& piece, int posX, int posY);
private:
    int width, height;
    std::vector<std::vector<char>> grid;
};

#endif // BOARD_H
