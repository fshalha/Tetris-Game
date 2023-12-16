#include <iostream>
#include "Board.h"        // Include your Board class header
#include "Piece.h"        // Include your Piece class header
#include "ThemeManager.h" // Include your ThemeManager class header
#include <conio.h>
class Game
{
public:
    Game() : board(10, 20), isGameOver(false), isGamePaused(false), currentPiece(Piece::Type::I)
    {
        // Initialize ThemeManager and other components
    }

    void run()
    {
        while (!isGameOver)
        {
            if (!isGamePaused)
            {
                handleInput(); // Handle player input
                updateGame();  // Update game state
            }
            render(); // Render the game state
        }
    }

    void togglePause()
    {
        isGamePaused = !isGamePaused;
    }

bool movePieceDown() {
    if (!canMoveDown()) {
        // Collision detected, piece cannot move down
        // Place the piece on the board and check for line clears
        board.placePiece(currentPiece.getBlocks(), pieceX, pieceY);
        checkForLineClears();
        spawnNewPiece(); // Spawn a new piece at the top
        return false;
    }
    pieceY++; // Move the piece down
    return true;
}

bool canMoveDown() {
    return board.canMoveDown(currentPiece.getBlocks(), pieceX, pieceY);
}

bool canMoveLeft() {
    return board.canMoveLeft(currentPiece.getBlocks(), pieceX - 1, pieceY);
}

bool canMoveRight() {
    return board.canMoveRight(currentPiece.getBlocks(), pieceX + 1, pieceY);
}

private:
    Board board;
    Piece currentPiece;
    bool isGameOver;
    bool isGamePaused;
    ThemeManager themeManager;
    int pieceX, pieceY;                  // Position of the current piece
    int width, height;                   // Dimensions of the game board
    std::vector<std::vector<char>> grid; // The game grid
    void handleInput()
    {
        if (_getch())
        {                        // Check if a keyboard key is hit
            char key = _getch(); // Get the hit key

            switch (key)
            {
            case 'a': // Move left
                if (canMoveLeft())
                {
                    pieceX--;
                }
                break;
            case 'd': // Move right
                if (canMoveRight())
                {
                    pieceX++;
                }
                break;

            case 'w': // Rotate
                currentPiece.rotate();
                // Check and resolve any collision after rotation
                break;
            case 's': // Speed up descent
                if (canMoveDown())
                {
                    pieceY++;
                }
                break;
            case 'p': // Pause
                togglePause();
                break;
                // Add more cases as needed
            }
        }
    }

    void updateGame()
    {
        // Example logic for moving the current piece down each frame
        if (!movePieceDown())
        {
            board.placePiece(currentPiece.getBlocks(), pieceX, pieceY);
            checkForLineClears();
            spawnNewPiece();
        }
    }

 

   void checkForLineClears() {
    for (int row = 0; row < height; ++row) {
        if (isRowFull(row)) {
            clearRow(row);
            shiftDownAboveRows(row);
        }
    }
}

bool isRowFull(int row) {
    // Check if every cell in the row is filled
    return board.isRowFull(row);
}

void clearRow(int row) {
    // Clear the row
    board.clearRow(row);
}

void shiftDownAboveRows(int clearedRow) {
    // Shift down all rows above the cleared row
    board.shiftDownRowsAbove(clearedRow);
}


void spawnNewPiece() {
    Piece::Type nextPieceType = static_cast<Piece::Type>(rand() % 7);
    currentPiece = Piece(nextPieceType);
    pieceX = width / 2 - currentPiece.getWidth() / 2; // Center the piece horizontally
    pieceY = 0; // Start from the top of the board
}


void render() {
    system("cls"); // Clear the console (for Windows)
    board.display();
    // Display next piece, score, level, etc.
}
};

int main()
{
    Game tetrisGame;
    tetrisGame.run();
    return 0;
}
