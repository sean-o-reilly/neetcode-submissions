#include <ranges>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hm;

        for (const auto& str : strs)
        {
            std::string key{str};
            std::ranges::sort(key);
            hm[key].push_back(str);
        }
        return hm | std::views::values | std::ranges::to<std::vector>();
    }
};
