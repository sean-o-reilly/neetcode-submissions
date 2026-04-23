class Solution {
public:

    enum class CellStatus : int
    {
        Unknown,
        Pacific,
        Atlantic,
        Both
    };

    using StatusMap = vector<vector<CellStatus>>;
    using HeightMap = vector<vector<int>>;

    void updateCellStatus(int row, int col, StatusMap& statuses, CellStatus newStatus)
    {
        CellStatus& curr = statuses.at(row).at(col);

        if (curr == CellStatus::Both)
        {
            return;
        }

        if (newStatus == CellStatus::Both)
        {
            curr = CellStatus::Both;
            return;
        }

        if (curr == CellStatus::Unknown)
        {
            curr = newStatus;
            return;
        }

        if (
            (curr == CellStatus::Pacific && newStatus == CellStatus::Atlantic) ||
            (curr == CellStatus::Atlantic && newStatus == CellStatus::Pacific)
            )
        {
            curr = CellStatus::Both;
        }
    }

    void printCell(CellStatus toPrint)
    {
        switch (toPrint)
        {
            case CellStatus::Pacific:
                std::cout << "(P)";
                break;
            case CellStatus::Atlantic:
                std::cout << "(A)";
                break;
            case CellStatus::Both:
                std::cout << "(B)";
                break;
            default:
                std::cout << "(U)";
                break;
        }
    }

    void dfs(int row, int col, HeightMap& heights, StatusMap& statuses)
    {
        std::cout << "[" << row << ", " << col << "] ";

        if (statuses.at(row).at(col) != CellStatus::Unknown)
        {
            printCell(statuses.at(row).at(col));
            return;
        }

        // If on border
        if (row == 0 || col == 0)
        {
            updateCellStatus(row, col, statuses, CellStatus::Pacific);
        }
        if (row == heights.size() - 1 || col == heights.at(0).size() - 1)
        {
            updateCellStatus(row, col, statuses, CellStatus::Atlantic);
        }


        std::vector<std::pair<int, int>> neighbors;

        neighbors.push_back({row - 1, col});
        neighbors.push_back({row + 1, col});
        neighbors.push_back({row, col - 1});
        neighbors.push_back({row, col + 1});

        for (auto [nRow, nCol] : neighbors)
        {
            // Only count neighbors that are in bounds and <= height
            if (nRow < 0 || nCol < 0) continue;
            if (nRow >= heights.size() ||nCol >= heights.at(0).size()) continue;

            if (heights.at(nRow).at(nCol) > heights.at(row).at(col)) continue;

            dfs(nRow, nCol, heights, statuses);
            CellStatus neighborStatus = statuses.at(nRow).at(nCol);
            updateCellStatus(row, col, statuses, neighborStatus);
        }

        printCell(statuses.at(row).at(col));
    }

    vector<vector<int>> pacificAtlantic(HeightMap& heights)
    {
        StatusMap statuses(heights.size(), std::vector<CellStatus>(heights.at(0).size(), CellStatus::Unknown));

        for (int i = 0; i < heights.size(); ++i)
        {
            vector<int>& row = heights.at(i);

            for (int j = 0; j < row.size(); ++j)
            {
                dfs(i, j, heights, statuses);
                std::cout << std::endl;
            }
        }

        vector<vector<int>> res;

        for (int i = 0; i < heights.size(); ++i)
        {
            for (int j = 0; j < heights.at(0).size(); ++j)
            {
                CellStatus currStatus = statuses.at(i).at(j);
                if (currStatus == CellStatus::Both)
                {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};


/*

DFS + memoization may help here
    Only traverse to heights lower than current height
    Prefer neighbors with greatest height

Strategy:
    Mark each cell to save time
        For each cell: can this cell reach the pacific, can this cell reach the atlantic?


Pseudocode:
    for each cell, call dfs

    void dfs(currIndices, heights, statuses)

        If curr status is NOT unknown, return/skip
        
        If on border:
            set curr to:
                corners set both
                left and top set atlantic
                right and bottom set pacific

        for neighbors <= curr height, sorted greatest to least:
            neighbor status = dfs(neighborIndices, height, statuses)

            update curr status based on neighbor status
                



*/