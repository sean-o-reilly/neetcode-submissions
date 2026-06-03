class Solution {
public:
    using Grid = std::vector<std::vector<bool>>;
    bool dfs(int row, int col, Grid seen, const vector<vector<char>>& board, const string& word, int idx)
    {
        // failed search
        if (idx >= word.length()) return false;
        // bounds
        if (row < 0 || row >= board.size() || col < 0 || col >= board.at(0).size()) return false;

        if (seen.at(row).at(col)) return false;
        seen.at(row).at(col) = true;
        std::cout << row << " " << col << std::endl;

        if (board.at(row).at(col) == word.at(idx))
        {
            if (idx == word.length() - 1) return true;

            ++idx;
            return
                dfs(row + 1, col, seen, board, word, idx) ||
                dfs(row - 1, col, seen, board, word, idx) ||
                dfs(row, col + 1, seen, board, word, idx) ||
                dfs(row, col - 1, seen, board, word, idx);
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int width = board.at(0).size();
        
        for (int r = 0; r < board.size(); ++r)
        {
            for (int c = 0; c < width; ++c)
            {
                if (board.at(r).at(c) == word.at(0))
                {
                    Grid seen(board.size(), std::vector<bool>(width, false));
                    if (dfs(r, c, seen, board, word, 0))
                        return true;
                }
            }
        }
        return false;
    }
};

/*
dfs

linear search for start letter
when found. run dfs search by letter

search:
    dfs
    mark seen squares on a per search basis to avoid cycles
    end search if word is not found within length# of letters


exist():
    for row in board
        for col in row
            if cell == word[0]
                # start search
                seen[][]
                if dfs(row, col, seen, word, 0)
                    return true
    
    return false # not found

dfs(row, col, &seen, &word, idx):
    # base cases
    if (idx >= word length) return false # word not found
    if (row col out of bounds) return false
    if (row col seen already) return false

    # recursive cases
    if (row, col == word[idx]) 
        seen[row][col] = true # mark as seen

        if (idx is word.size - 1) # last letter
            return true
        else continue search,
            ++idx
            dfs(row + 1, col,)
            dfs(row - 1, col)
            dfs(row, col + 1)
            dfs(row, col - 1)
            if any return true,
                return true else return false
    return false

*/