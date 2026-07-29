class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        using Cell = std::pair<int, int>; // row col pairs
        std::queue<std::vector<Cell>> q;
        std::vector<Cell> level;

        for (auto row{0uz}; row < grid.size(); ++row)
        {
            for (auto col{0uz}; col < grid.at(row).size(); ++col)
            {
                if (grid.at(row).at(col) == 2) // Add all rotten fruit to queue
                {
                    level.push_back({row, col});
                }
            }
        }

        q.push(level);
        int minutes = 0;

        while (!q.empty())
        {
            auto currLevel = q.front();
            q.pop();

            std::vector<Cell> nextLevel;

            auto getNeighbors = [&](auto r, auto c)
            {
                std::vector<Cell> res;
                if (r - 1 >= 0) // top neighbor
                {
                    res.push_back({r - 1, c});
                }
                if (r + 1 < grid.size()) // bottom neighbor
                {
                    res.push_back({r + 1, c});
                }
                if (c - 1 >= 0) // left neighbor
                {
                    res.push_back({r, c - 1});
                }
                if (c + 1 < grid.at(r).size()) // right neighbor
                {
                    res.push_back({r, c + 1});
                }
                return res;
            };

            for (const auto& [r, c] : currLevel)
            {
                std::cerr << r << "," << c << std::endl;

                // If neighbor in bounds and non-rotten, mark as rotten and add to next level
                for (const auto& [nR, nC] : getNeighbors(r, c))
                {
                    if (grid.at(nR).at(nC) != 1)
                    {
                        continue;
                    }

                    grid.at(nR).at(nC) = 2;
                    nextLevel.push_back({nR, nC});
                }
            }

            if (!nextLevel.empty())
            {
                ++minutes;
                q.push(nextLevel);
            }
        }

        for (const auto& row : grid)
        {
            if (std::ranges::find(row, 1) != row.end())
            {
                return -1; // At least one fruit never rotted
            }
        }

        return minutes;
    }
};

/*
1. setup
    create a queue of list(indices) # level-order bfs
    push all rotting indices to the queue
    minutes = 0
2. bfs
    while queue is non empty
        ++minutes

        indices  = queue.pop()

        level = []

        for curr in indices:
            for each neighbor of curr,
                if neighbor is fresh:
                    mark it as rotting
                    level.push(neighbor)

        queue.push(level)

    if any fresh fruit left, return -1
    else return minutes
            
        

*/
