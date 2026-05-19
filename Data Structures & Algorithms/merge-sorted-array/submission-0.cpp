class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        const auto sz = nums1.size();

        int j = 0;
        for (int i = m; i < sz; ++i)
            nums1.at(i) = nums2.at(j++);

        std::ranges::sort(nums1);
    }
};