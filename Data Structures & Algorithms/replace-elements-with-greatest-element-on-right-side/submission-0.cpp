#include <utility>

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        int max = -1;

        for (int i = arr.size() - 1; i >= 0; --i)
        {
            int curr = std::exchange(arr.at(i), max);
            max = std::max(max, curr);
        }

        return arr;
    }
};

/*
Go backwards?

[2,4,5,3,1,2]

max = 0

at last idx, just put -1
    but, we know a current max is 2 so far
max = 2

at second to last idx, we know the current max is 2
    put 2

at third to last, we have a new max, 3. but this
    is not inclusive so we put max first, then update after

at 4th to last, put the curr max 3, then update it to 5

*/