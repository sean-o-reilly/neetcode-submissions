class Solution {
public:

    void search(int row, int col, const int m, const int n, int& paths)
    {
        if (row == m - 1 && col == n - 1) // found trophy
        {
            ++paths;
            return;
        }
        else if (row >= m || col >= n) // out of bounds
        {
            return;
        }

        search(row, col + 1, m, n, paths); // try right
        search(row + 1, col, m, n, paths); // try down
    }

    int uniquePaths(int m, int n) 
    {
        int paths = 0;

        search(0, 0, m, n, paths);

        return paths;
    }
};

// how many ways to move from the top left corner to the bottom right corner of a grid?

// brute force: try every way to get to bottom right corner, go randomky a thousand times etc.\
// generate all possibly permutations?

// 3x6
// R D R D R R R 
// D D R R R R R 
// R R R R R D D 
// D R R R R R D 
// R R D D R R R 
// R D D D D R R
// ...
// path length = 7

// 3x3 grid
// R D R D 
// D R D R 
// R R D D 
// D D R R 
// R D D R 
// D R R D
// path length = 4

// 3x5
// D R R R R D 
// R R R R D D 
// D D R R R R 
// path length = 3 + 5 - 2 = 8 -2 = 6

// 2x2 grid
// R D
// D R
// path length = 2

// path length is a constant across all grids, maybe there's a way to calculate it?

// path length = m + n - 2
// generate a decision tree or number of permutations based on binary decision tree with height path length

// recursive search. 
// starting at top left:

// search():
// are we out of bounds? cancel search
// is this the trophy? 
// if yes, end search successfully
// else,
// check if right is trophy.
// check if down is trophy. 
// avoid using dfs or bfs, we don't want to find shortest path, we want to find all paths

