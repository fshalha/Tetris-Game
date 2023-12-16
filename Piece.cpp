#include <vector>

class Piece
{
public:
    enum Type
    {
        I,
        O,
        T,
        S,
        Z,
        J,
        L
    };

    Piece(Type type) : type(type), orientation(0)
    {
        initializeBlocks();
    }

    void rotate()
    {
        orientation = (orientation + 1) % 4;
        initializeBlocks();
    }

    // Methods for movement and collision detection would be here

    const std::vector<std::vector<int>> &getBlocks() const
    {
        return blocks;
    }
    int getWidth() const {
    if (blocks.empty()) return 0;
    return blocks[0].size(); // Assuming blocks is a 2D vector representing the piece
}


private:
    Type type;
    int orientation;
    std::vector<std::vector<int>> blocks;

    void initializeBlocks()
    {
        blocks.clear();
        switch (type)
        {
        case I:
            if (orientation % 2 == 0)
                blocks = {{1, 1, 1, 1}};
            else
                blocks = {{1}, {1}, {1}, {1}};
            break;
        case O:
            blocks = {{1, 1},
                      {1, 1}};
            break;

        case T:
            if (orientation == 0)
                blocks = {{0, 1, 0}, {1, 1, 1}};
            else if (orientation == 1)
                blocks = {{1, 0}, {1, 1}, {1, 0}};
            else if (orientation == 2)
                blocks = {{1, 1, 1}, {0, 1, 0}};
            else
                blocks = {{0, 1}, {1, 1}, {0, 1}};
            break;

        case S:
            if (orientation % 2 == 0)
                blocks = {{0, 1, 1}, {1, 1, 0}};
            else
                blocks = {{1, 0}, {1, 1}, {0, 1}};
            break;

        case Z:
            if (orientation % 2 == 0)
                blocks = {{1, 1, 0}, {0, 1, 1}};
            else
                blocks = {{0, 1}, {1, 1}, {1, 0}};
            break;

        case J:
            if (orientation == 0)
                blocks = {{1, 0, 0}, {1, 1, 1}};
            else if (orientation == 1)
                blocks = {{1, 1}, {1, 0}, {1, 0}};
            else if (orientation == 2)
                blocks = {{1, 1, 1}, {0, 0, 1}};
            else
                blocks = {{0, 1}, {0, 1}, {1, 1}};
            break;

        case L:
            if (orientation == 0)
                blocks = {{0, 0, 1}, {1, 1, 1}};
            else if (orientation == 1)
                blocks = {{1, 0}, {1, 0}, {1, 1}};
            else if (orientation == 2)
                blocks = {{1, 1, 1}, {1, 0, 0}};
            else
                blocks = {{1, 1}, {0, 1}, {0, 1}};
            break;
        }
    }
};
