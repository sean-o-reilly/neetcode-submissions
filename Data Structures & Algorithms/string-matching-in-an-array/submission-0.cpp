class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        std::vector<std::string> res;

        for (auto i = 0u; i < words.size(); ++i)
        {
            const auto& currStr = words.at(i);

            for (auto j = 0; j < words.size(); ++j)
            {
                if (i == j) continue;

                const auto& other = words.at(j);
                if (other.find(currStr) != std::string::npos)
                {
                    res.push_back(currStr);
                    break;
                }
            }
        }

        return res;
    }
};


/*

brute force n^2, constant space:
    for each string,
        scan all other strings to see if curr string is a substring of another


optimal:

mass, as, hero, superhero
sort by length -> nlogn + n^2
as, mass, hero, superhero



neetcode, neeet, neet, code


tree?

neet -> neetcode -> neetcode.io

*/