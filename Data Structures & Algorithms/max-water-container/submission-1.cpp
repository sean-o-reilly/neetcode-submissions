class Solution {
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0;
        int right = heights.size() - 1;

        int max = 0;

        while (left < right)     
        {
            int area = std::min(heights.at(left), heights.at(right)) * (right - left);
            max = std::max(max, area);
            if (heights.at(left) <= heights.at(right))
            {
                ++left;
            }
            else
            {
                --right;
            }
        }

        return max;
    }
};

/*
area = min(left height, right height) * (right - left)
look for max area

two pointer
max width starts with left = 0, right = end - 1

move whichever pointer is lesser height to maximize height
while losing minimal width

[1, 1, 1, 999, 999, 1, 1]
6
5
4
3
2
999

[1, 2, 3, 4, 5]
[5, 4, 3, 2, 1]
[1, 999, 1, 1, 100, 999, 1]


*/