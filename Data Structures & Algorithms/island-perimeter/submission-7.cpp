class Solution {
public:
    static constexpr int land = 1;
    static constexpr int water = 0;

    int islandPerimeter(vector<vector<int>>& grid)
    {
        int perimeter = 0;
        const int width = grid.at(0).size();
        std::queue<std::pair<int, int>> q;
        bool done = false;
        std::vector<std::vector<bool>> seen(grid.size(), std::vector<bool>(width, false));

        for (int r = 0; r < grid.size(); ++r)
        {
            for (int c = 0; c < width; ++c)
            {
                if (grid.at(r).at(c) == land)
                {
                    seen.at(r).at(c) = true;
                    q.push({r, c});
                    done = true;
                    break;
                }
            }
            if (done) break;
        }

        auto newLand = [&grid, &width, &seen](int r, int c)
        {
            if (r >= 0
            && r < grid.size()
            && c >= 0
            && c < width
            && seen.at(r).at(c) == false
            && grid.at(r).at(c) == land)
            {
                seen.at(r).at(c) = true;
                return true;
            }
            return false;
        };

        while (!q.empty())
        {
            auto [row, col] = q.front();
            q.pop();

            if (row + 1 >= grid.size() || grid.at(row + 1).at(col) == water)
                ++perimeter;
            if (row - 1 < 0 || grid.at(row - 1).at(col) == water)
                ++perimeter;
            if (col + 1 >= width || grid.at(row).at(col + 1) == water)
                ++perimeter;
            if (col - 1 < 0 || grid.at(row).at(col - 1) == water)
                ++perimeter;
            
            if (newLand(row + 1, col))
                q.push({row + 1, col});
            if (newLand(row - 1, col))
                q.push({row - 1, col});
            if (newLand(row, col - 1))
                q.push({row, col - 1});
            if (newLand(row, col + 1))
                q.push({row, col + 1});
        }

        return perimeter;
    }
};

/*
traverse linearly until land it found
run DFS/BFS search to cover all land tiles
    perimeter += number of sides that touch water or go out of bounds (non land)

perimeter = 0
startRow = 0
startCol = 0

# find land, will always be exactly one island
for row = 0, row < rows
    for col = 0, col < cols
        if grid at row,col == land
            startRow = row
            startCol = col
            break

# run search
queue q (pair)
q add (startRow, startCol)

while q has elements:
    row, col = q.pop
    if row + 1 out of bounds, or row + 1 is water, ++perimeter
        ^ repeat for col +- 1, row - 1
*/