#pragma once

class Node
{
    public:
        bool visited;
        Node* up;
        Node* down;
        Node* left;
        Node* right;

        Node()
        {
            this->up = nullptr;
            this->down = nullptr;
            this->left = nullptr;
            this->down = nullptr;
            this->visited = false;
        }
};