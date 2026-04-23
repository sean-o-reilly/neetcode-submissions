class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> res;

        if (numRows >= 1)
        {
            res.push_back({1});
        }

        for (int rowIdx = 0; rowIdx < numRows - 1; ++rowIdx)
        {
            std::vector<int>& row = res.at(rowIdx);
            int middleIdx = (row.size()) / 2;

            std::vector<int> newRow = {1};
            newRow.reserve(row.size() + 1);

            for (int i = 0; i < middleIdx; ++i)
            {
                int windowSum = row.at(i) + row.at(i + 1);
                newRow.push_back(windowSum);
            }

            if (row.size() % 2 == 0) --middleIdx;

            for (int i = middleIdx; i >= 0; --i)
            {
                newRow.push_back(newRow.at(i));
            }

            res.push_back(newRow);
        }

        return res;
    }
};

/*

[
    [1],
    [1,1],
    [1,2,1],
    [1,3,3,1],
    [1,4,6,4,1], 
    [1,5,10,10,5,1]
]

Triangle is symmetrical - avoid recalculations!

psuedocode:
    middle index = row.size / 2

    newRow = [1]

    for i = 0, i < middle index, ++i
        windowSum = row[i] + row[i + 1]

    mirror newRow

    middle index = newRow size / 2

    if row is even, subtract 1 from middle index (dont mirror middle twice to make another even row)

    for i = middle index, i >= 0, --i
        newRow.push_back(newRow[i])



*/