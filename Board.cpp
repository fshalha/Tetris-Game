#include <vector>
#include <iostream>

class Board {
public:
    Board(int width, int height) : width(width), height(height), grid(height, std::vector<char>(width, ' ')) {}

    void update() {
        // Add logic for updating the board state
        // This could include placing pieces, checking for completed lines, etc.
    }

    void placePiece(const std::vector<std::vector<int>>& piece, int posX, int posY) {
        // Logic for placing a piece on the board at a specified position
        for (int i = 0; i < piece.size(); i++) {
            for (int j = 0; j < piece[i].size(); j++) {
                if (piece[i][j] == 1) {
                    grid[posY + i][posX + j] = 'X'; // Mark the occupied cells
                }
            }
        }
        // After placing a piece, check for full lines
    for (int row = 0; row < height; ++row) {
        if (isRowFull(row)) {
            clearRow(row);
            shiftDownRowsAbove(row);
        }
    }
    }

    void clearLines() {
        // Logic for clearing completed lines
    }

    void display() const {
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << " ";
            }
            std::cout << std::endl;
        }
    }
    void shiftDownRowsAbove(int clearedRow) {
    for (int row = clearedRow - 1; row >= 0; --row) {
        for (int col = 0; col < width; ++col) {
            grid[row + 1][col] = grid[row][col]; // Shift each cell down
        }
    }
    // Set the top row to empty after shifting
    for (int col = 0; col < width; ++col) {
        grid[0][col] = ' ';
    }
}
void clearRow(int row) {
    for (int col = 0; col < width; ++col) {
        grid[row][col] = ' '; // Set each cell in the row to empty
    }
}


bool isRowFull(int row) {
    for (int col = 0; col < width; ++col) {
        if (grid[row][col] == ' ') { // Assuming ' ' represents an empty cell
            return false;
        }
    }
    return true;
}
bool canMoveDown(const std::vector<std::vector<int>>& piece, int posX, int posY) {
    for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[i].size(); j++) {
            if (piece[i][j] == 1) { // Check only the filled parts of the piece
                int newY = posY + i + 1; // New Y position if moved down
                if (newY >= height || grid[newY][posX + j] != ' ') {
                    // Collision with bottom or another piece
                    return false;
                }
            }
        }
    }
    return true;
}
bool canMoveLeft(const std::vector<std::vector<int>>& piece, int posX, int posY) {
    for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[i].size(); j++) {
            if (piece[i][j] == 1) { // Check only the filled parts of the piece
                int newX = posX + j - 1; // New X position if moved left
                if (newX < 0 || grid[posY + i][newX] != ' ') {
                    // Collision with left wall or another piece
                    return false;
                }
            }
        }
    }
    return true;
}

bool canMoveRight(const std::vector<std::vector<int>>& piece, int posX, int posY) {
    for (int i = 0; i < piece.size(); i++) {
        for (int j = 0; j < piece[i].size(); j++) {
            if (piece[i][j] == 1) { // Check only the filled parts of the piece
                int newX = posX + j + 1; // New X position if moved right
                if (newX >= width || grid[posY + i][newX] != ' ') {
                    // Collision with right wall or another piece
                    return false;
                }
            }
        }
    }
    return true;
}



private:
    int width, height;
    std::vector<std::vector<char>> grid;
    // Other necessary members...
};
