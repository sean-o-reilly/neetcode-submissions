class Solution {
public:
    using Grid = vector<vector<int>>;

    int searchRow(Grid& matrix, int target)
    {
        int low = 0;
        int high = matrix.size() - 1;
        int mid = (high + low) / 2;

        while (low <= high)
        {
            int curr = matrix.at(mid).at(0);

            if (target >= curr)
            {
                if (mid == matrix.size() - 1)
                {
                    return mid;
                }
                else
                {
                    if (target < matrix.at(mid + 1).at(0))
                    {
                        return mid;
                    }
                }
            }

            if (target < curr)
            {
                high = mid - 1;
            }
            else if (target > curr)
            {
                low = mid + 1;
            }

            mid = (high + low) / 2;
        }

        return -1;
    }

    bool binarySearch(std::vector<int>& vec, int target)
    {
        int low = 0;
        int high = vec.size() - 1;
        int mid;

        while (low <= high)
        {
            mid = (high + low) / 2;

            if (vec.at(mid) == target)
            {
                return true;
            }
            else if (target < vec.at(mid))
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return false;
    }

    bool searchMatrix(Grid& matrix, int target)
    {
        int targetRow = searchRow(matrix, target);
        std::cout << targetRow << std::endl;

        if (targetRow != -1)
        {
            return binarySearch(matrix.at(targetRow), target);
        }

        return false;
    }
};

/*

Binary search for row
    low = first row
    high = last row

    mid = high + low / 2

    while low < high

        If search less than mid val
        else If search greater or equal to mid val AND&& less than high val
            return mid -> target is in this row
            high = mid - 1
        else If search greater than mid val
            low = mid + 1

        mid = high + low / 2



Binary search for col

*/