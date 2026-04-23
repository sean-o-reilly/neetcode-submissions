class Solution {
public:


    bool allUnique(const vector<char>& section)
    {
        const char EMPTY = '.';

        std::unordered_set<char> unique;

        for (char c : section)
        {
            if (unique.count(c))
            {
                return false;
            }

            if (c != EMPTY)
            {
                unique.insert(c);       
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board)
    {
        const int BOARD_SIZE = board.size();
        const char EMPTY = '.';

        for (auto row : board)
        {
            if (!allUnique(row))
            {
                return false;
            }
        }

        for (int c = 0; c < BOARD_SIZE; ++c)
        {
            vector column(9, EMPTY);

            for (int r = 0; r < BOARD_SIZE; ++r)
            {
                column[r] = board[r][c];
            }

            if (!allUnique(column))
            {
                return false;
            }
        }

        for (int r = 0; r < BOARD_SIZE; r += 3)
        {
            for (int c = 0; c < BOARD_SIZE; c += 3)
            {
                vector<char> subbox;

                for (int subR = r; subR < r + 3; ++subR)
                {
                    for (int subC = c; subC < c + 3; ++subC)
                    {
                        subbox.push_back(board[subR][subC]);
                    }
                }

                if (!allUnique(subbox))
                {
                    return false;
                }
                else
                {
                    std::cout << r << ", " << c << " subbox unique" << std::endl;
                    for (char c : subbox) std::cout << c;
                    std::cout << std::endl;
                }
            }
        }

        return true;
    }
};


/*
Each row must contain unique 1-9
Each col must contain unique 1-9
Each subbox must contain unique 1-9

Solution:
    Check all 9 rows of the board
        For each row,
            check if the row is unique numbers only
    Check all 9 columns of the board
        For each col,
            check if the col is unique numbers only
    Check all sub boxes of the board
        For each box
            check if the box is unique numbers only

    If at any point one of these is invalid/false, return false
    else return true

    To check for unique: add numbers to a set, if at any point the number we're adding is already in the set, return false

    O(n) time & space where n is number of cells in the board

    Way to avoid redundant checks?


*/