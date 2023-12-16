#include <iostream>
#include "Board.h"  // Include your Board class header
#include "Piece.h"  // Include your Piece class header
#include "ThemeManager.h"  // Include your ThemeManager class header

class Game {
public:
    Game() : board(10, 20), isGameOver(false), isGamePaused(false), currentPiece(Piece::Type::I) {
        // Initialize ThemeManager and other components
    }

    void run() {
        while (!isGameOver) {
            if (!isGamePaused) {
                handleInput();  // Handle player input
                updateGame();   // Update game state
            }
            render();  // Render the game state
        }
    }

    void togglePause() {
        isGamePaused = !isGamePaused;
    }

private:
    Board board;
    Piece currentPiece;
    bool isGameOver;
    bool isGamePaused;
    ThemeManager themeManager;

   void handleInput() {
    if (_getch()) { // Check if a keyboard key is hit
        char key = _getch(); // Get the hit key

        switch (key) {
            case 'a': // Move left
                // Logic to move the piece left
                break;
            case 'd': // Move right
                // Logic to move the piece right
                break;
            case 'w': // Rotate
                currentPiece.rotate();
                // Check and resolve any collision after rotation
                break;
            case 's': // Speed up descent
                // Logic to increase the descent speed of the piece
                break;
            case 'p': // Pause
                togglePause();
                break;
            // Add more cases as needed
        }
    }
}

void updateGame() {
        // Example logic for moving the current piece down each frame
        if (!movePieceDown()) {
            board.placePiece(currentPiece.getBlocks(), pieceX, pieceY);
            checkForLineClears();
            spawnNewPiece();
        }
    }

    bool movePieceDown() {
    // Assuming pieceY is the vertical position of the current piece
    // Check if moving down is possible without collision
    if (/* condition to check collision with bottom or other pieces */) {
        return false;  // Collision detected, piece cannot move down
    }
    pieceY++;  // Move the piece down
    return true;
}


    void checkForLineClears() {
    for (int row = 0; row < height; ++row) {
        if (/* condition to check if the row is full */) {
            // Clear the line
            for (int col = 0; col < width; ++col) {
                grid[row][col] = ' ';  // Assuming an empty cell is represented by a space
            }
            // Logic to shift down all rows above the cleared line
        }
    }
}

   void spawnNewPiece() {
    Piece::Type nextPieceType = static_cast<Piece::Type>(rand() % 7);  // Select a random piece type
    currentPiece = Piece(nextPieceType);
    pieceX = width / 2;  // Center the piece horizontally
    pieceY = 0;  // Start from the top of the board
}

    void render() {
        // Render the game state (e.g., displaying the board, current piece, and game info)
        // Placeholder for rendering logic
        board.display();
    }
};

int main() {
    Game tetrisGame;
    tetrisGame.run();
    return 0;
}
