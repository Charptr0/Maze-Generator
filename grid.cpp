#include <vector>
#include "Cell/cell.h"
#include <ctime>
#include <iostream>

using std::vector;

vector<vector<Cell>> generateGrid(const int RESOLUTION[2], const int SIDE_LENGTH, const int WALL_LENGTH)
{
    const int TOTAL_COLS = RESOLUTION[0] / (SIDE_LENGTH + WALL_LENGTH);
    const int TOTAL_ROWS = RESOLUTION[1] / (SIDE_LENGTH + WALL_LENGTH);

    std::srand(time(NULL));

    vector<Cell>cols(TOTAL_COLS + 1, Cell());
    vector<vector<Cell>>grid(TOTAL_ROWS + 1, cols);

    return grid;
}

bool validCell(const vector<vector<Cell>>&grid, const int row, const int col)
{
    if(row >= grid.size() || col >= grid[0].size() || grid[row][col].visited) return false;

    return true;
}

vector<int> aviliableSpaces(const vector<vector<Cell>>&grid, const int row, const int col)
{
    vector<int>freeSpaces;

    if(validCell(grid, row +1 ,col)) freeSpaces.push_back(Directions::UP);
    if(validCell(grid, row - 1 ,col)) freeSpaces.push_back(Directions::DOWN);
    if(validCell(grid, row ,col - 1)) freeSpaces.push_back(Directions::LEFT);    
    if(validCell(grid, row, col + 1)) freeSpaces.push_back(Directions::RIGHT);

    return freeSpaces;
}

int randomIndex(const int size)
{
    return rand() % size;
}
