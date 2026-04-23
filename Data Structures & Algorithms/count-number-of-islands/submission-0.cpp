class Solution {
public:

    // collect all parts of this island into the visited container
    void dfs_island(vector<vector<char>>& grid, std::pair<int, int> curr, std::set<std::pair<int, int>>& visited)
    {
        // base case
        std::cout << "DFS: " << curr.first << " " << curr.second << std::endl;
        // check visited 
        if (visited.count(curr)) return;

        // check out of bounds
        int row = curr.first; // i = row
        int col = curr.second; // j = col
        if (row < 0 || row >= grid.size()) return;
        if (col < 0 || col >= grid[row].size()) return;

        char val = grid[row][col];
        if (val == '0') return;

        // recursive case
        // insert curr into visited
        visited.insert(curr);
        std::cout << "New: " << curr.first << " " << curr.second << std::endl;
        // up
        dfs_island(grid, {row - 1, col}, visited);
        // right
        dfs_island(grid, {row, col + 1}, visited);
        // down 
        dfs_island(grid, {row + 1, col}, visited);
        // left 
        dfs_island(grid, {row, col - 1}, visited);

        // done with this branch of search
    }



    int numIslands(vector<vector<char>>& grid) 
    {
        int islands = 0;
        std::set<std::pair<int, int>> visited;

        for (int i = 0; i < grid.size(); ++i) // for row
        {
            for (int j = 0; j < grid[i].size(); ++j) // for col in row
            {
                char val = grid[i][j];
                if (val == '0') continue;

                // We've found an potential island
                std::pair<int, int> islandStart{i, j};

                if (visited.count(islandStart)) continue; // already been here
                std::cout << "==== new island" << std::endl;

                // Start dfs search
                dfs_island(grid, islandStart, visited);
                ++islands;
            }
        }

        return islands;
    }
};

// traverse the grid, cell by cell. Use DFS to find islands

// store an int we can increment on each dfs search
// store a set of all indices visited rather than groupings

// when we reach a 1:
//      ignore if already visited
//     if we have not visited this 1, we've found a new island:
//
//      increment count by one
//      add this 1 to our visited set at the back of the vector

//      perform DFS on this 1. we can do this in clockwise
//      order. up, right, down, left
//      

//      call this algorithm on the cell to the nth direction ^

//      finish search and unwind recursively to previous cell


// return count