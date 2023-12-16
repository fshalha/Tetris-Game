#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece {
public:
    enum Type { I, O, T, S, Z, J, L };

    Piece(Type type);
    void rotate();
    const std::vector<std::vector<int>>& getBlocks() const;
    int getWidth() ;


private:
    Type type;
    int orientation;
    std::vector<std::vector<int>> blocks;
    void initializeBlocks();
};

#endif // PIECE_H
