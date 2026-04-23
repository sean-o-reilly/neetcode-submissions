class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        std::unordered_set<int> rowsToZero;
        std::unordered_set<int> colsToZero;

        for (int row = 0; row < matrix.size(); ++row)
        {
            for (int col = 0; col < matrix.at(0).size(); ++col)
            {
                if (matrix[row][col] == 0)
                {
                    rowsToZero.insert(row);
                    colsToZero.insert(col);
                }
            }
        }

        for (int row : rowsToZero)
        {
            std::fill(matrix.at(row).begin(), matrix.at(row).end(), 0);
        }

        for (int col : colsToZero)
        {
            for (int row = 0; row < matrix.size(); ++row)
            {
                matrix[row][col] = 0;
            }
        }
    }
};

/*

    store a set of all rows that contain a zero, and a set for cols with zero
    rows = {1}
    cols = {1}

    For each column, zero the column
    For each row, zero the row

    zero column 1, zero row 1

    - Avoids redundant zeros and incorrect answers

*/