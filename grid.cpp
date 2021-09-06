#include <vector>

using std::vector;

vector<vector<int>> generateGrid(const int RESOLUTION[2], const int SIDE_LENGTH, const int WALL_LENGTH)
{
    const int TOTAL_COLS = RESOLUTION[0] / (SIDE_LENGTH + WALL_LENGTH);
    const int TOTAL_ROWS = RESOLUTION[1] / (SIDE_LENGTH + WALL_LENGTH);

    vector<int>cols(TOTAL_COLS + 1, 0);
    vector<vector<int>>grid(TOTAL_ROWS + 1, cols);

    grid[0][0] = 1;

    return grid;
}
