class Solution {
public:
    using Grid = vector<vector<int>>;

    void islandSize(Grid& grid, int row, int col, std::vector<std::vector<bool>>& visited, int& count)
    {
        const int rows = grid.size();
        const int cols = grid[0].size();

        // base case
        if (row >= rows || row < 0) return;
        if (col >= cols || col < 0) return;
        if (visited[row][col]) return;
        if (grid[row][col] == 0) return;

        std::cout << "Seaching island : " << row << " " << col << std::endl;

        // recursive case
        visited[row][col] = true;

        // try all four directions - up down left right
        ++count;

        islandSize(grid, row - 1, col, visited, count);
        islandSize(grid, row + 1, col, visited, count);
        islandSize(grid, row, col - 1, visited, count);
        islandSize(grid, row, col + 1, visited, count);
    }


    int maxAreaOfIsland(Grid& grid)
    {
        if (!grid.size()) return -1;

        const int rows = grid.size();
        const int cols = grid[0].size();

        std::vector<std::vector<bool>> visited(rows);
        visited.assign(rows, std::vector<bool>(cols,false));

        int maxSize = 0;

        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int islandArea = 0;
                    islandSize(grid, i, j, visited, islandArea);

                    maxSize = std::max(maxSize, islandArea);
                }
                visited[i][j] = true;
            }
        }

        return maxSize;
    }
};


/*

DFS, tracking max size of each island found

keep a hash set of visited indices
keep a max island size

loop over row,col values
    if the index is a 1,
        run a DFS search for more 1's
        increment a count each time another piece of island is found
        update max island size
        add index to the visited set
    if the index is a 0, skip it
    if the index is in visited, skip it

*/
