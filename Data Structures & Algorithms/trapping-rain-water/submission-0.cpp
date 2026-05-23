class Solution {
public:
    int trap(vector<int>& height)
    {
        // calculate rolling max's
        std::vector<int> leftMax(height.size(), 0);
        std::vector<int> rightMax(height.size(), 0);
        auto max = [](int a, int b){ return std::max(a, b);};
        std::partial_sum(height.begin(), height.end(), leftMax.begin(), max);
        std::partial_sum(height.rbegin(), height.rend(), rightMax.rbegin(), max);

        // get min of each index in left max and right max
        std::vector<int> min(height.size());
        std::transform(leftMax.begin(), leftMax.end(), rightMax.begin(),
            min.begin(), [](int left, int right){ return std::min(left, right);});
     
        int sum = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            if (height.at(i) < min.at(i))
                sum += min.at(i) - height.at(i);
        }

        return sum;
    }
};
