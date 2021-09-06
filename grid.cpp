#include <vector>
#include "Cell/cell.h"
#include <iostream>

using std::vector;

vector<vector<Cell>> generateGrid(const int RESOLUTION[2], const int SIDE_LENGTH, const int WALL_LENGTH)
{
    const int TOTAL_COLS = RESOLUTION[0] / (SIDE_LENGTH + WALL_LENGTH);
    const int TOTAL_ROWS = RESOLUTION[1] / (SIDE_LENGTH + WALL_LENGTH);

    vector<Cell>cols(TOTAL_COLS + 1, Cell());
    vector<vector<Cell>>grid(TOTAL_ROWS + 1, cols);

    return grid;
}
