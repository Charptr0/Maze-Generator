#pragma once

enum Directions
{
    UP, DOWN, LEFT, RIGHT
};

class Cell
{
    public:
        bool visited;
        bool cursor;
        bool upConnected;
        bool downConnected;
        bool leftConnected;
        bool rightConnected;

        Cell()
        {
            this->visited = false;
            this->cursor = false;
            this->upConnected = false;
            this->downConnected = false;
            this->leftConnected = false;
            this->rightConnected = false;
        }

        void reset()
        {
            this->visited = false;
            this->cursor = false;
            this->upConnected = false;
            this->downConnected = false;
            this->leftConnected = false;
            this->rightConnected = false;
        }
};