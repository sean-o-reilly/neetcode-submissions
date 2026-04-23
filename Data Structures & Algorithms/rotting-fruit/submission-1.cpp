class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        using Cell = std::pair<int, int>;

        std::vector<std::vector<bool>> seen(grid.size(), std::vector(grid.at(0).size(), false));

        std::queue<Cell> q;

        int noFruit = true;
        for (int row = 0; row < grid.size(); ++row)
        {
            for (int col = 0; col < grid.at(0).size(); ++col)
            {
                if (grid[row][col] == 2) // push rotten starts
                {
                    q.push({row, col});
                }
                else if (grid[row][col] == 1)
                {
                    noFruit = false;
                }
            }
        }

        if (noFruit) return 0;

        int minute = -1;

        if (q.empty()) return minute;

        while (!q.empty())
        {
            std::vector<Cell> neighbors;

            while (!q.empty())
            {
                Cell curr = q.front();
                q.pop();

                int row = curr.first;
                int col = curr.second;

                if (row < 0 || row >= grid.size()) continue;
                if (col < 0 || col >= grid.at(0).size()) continue;

                if (!seen.at(row).at(col) && grid.at(row).at(col) != 0)
                {
                    std::cout << row << ", " << col << std::endl;
                    seen.at(row).at(col) = true;
                    
                    neighbors.push_back({row - 1, col});
                    neighbors.push_back({row + 1, col});
                    neighbors.push_back({row, col + 1});
                    neighbors.push_back({row, col - 1});
                }
            }

            ++minute;
            std::cout << "\n";

            for (Cell neighbor : neighbors) q.push(neighbor);
        }

        for (int row = 0; row < seen.size(); ++row)
        {
            for (int col = 0; col < seen.size(); ++col)
            {
                if (seen[row][col] == false && grid[row][col] == 1)
                {
                    return -1; // fruit was not seen by BFS
                }
            }
        }
        return minute - 1;
    }

};

/*

BFS:

    Queue

    For each cell, if cell is rot, add to queue

    while queue not empty

        neighbors vector

        while queue not empty 
            Curr = pop front of queue
            For neighbor of curr
                if neighbor not already seen,
                    add to neighbors and mark as seen

        Increment time needed this wave
        Add all neighbors to queue

*/
