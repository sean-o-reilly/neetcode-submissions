class Solution {
public:
    bool isPathCrossing(string path)
    {
        if (path.length() < 2) return false;

        using Grid = std::vector<std::vector<bool>>;
        Grid grid(path.size() * 2 + 1, std::vector<bool>(path.size() * 2 + 1));

        const int offset = grid.size() / 2;
        int x = offset;
        int y = offset;
        grid.at(x).at(y) = true;

        for (const auto dir : path)
        {
            if (dir == 'N')
            {
                ++y;
            }
            else if (dir == 'S')
            {
                --y;
            }
            else if (dir == 'E')
            {
                ++x;
            }
            else if (dir == 'W')
            {
                --x;
            }

            if (grid.at(x).at(y)) return true;

            grid.at(x).at(y) = true;
        }

        return false;
    }
};

/*
2 stacks

DFS cycle detection
*/