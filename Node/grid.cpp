#include "node.h"
#include <vector>

using std::vector;

Node* _connectNeighbors(vector<vector<Node*>>&grid, int row, int col)
{
    if(row >= grid.size() || col >= grid[0].size()) return nullptr;

    else return grid[row][col];
}

vector<vector<Node*>> generateGrid(const int RESOLUTION[2], const int sideLength)
{
    const int total_cols = RESOLUTION[0] / sideLength;
    const int total_rows = RESOLUTION[1] / sideLength;

    vector<Node*>col(total_cols + 1, new Node());

    vector<vector<Node*>>grid(total_rows + 1, col);

    grid[0][0]->visited = true;

    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid[i].size(); i++)
        {
            Node* cell = grid[i][j];        
            
            cell->up = _connectNeighbors(grid, i+1, j);
            cell->down = _connectNeighbors(grid, i-1, j);
            cell->left = _connectNeighbors(grid, i, j-1);
            cell->right = _connectNeighbors(grid, i, j+1);
        }
    }
    
    return grid;
}
