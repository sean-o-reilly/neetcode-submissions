class Solution {
public:
    using EdgeMap = std::unordered_map<int, std::unordered_set<int>>;

    bool helper(const EdgeMap& hm, int currNode, int prevNode, std::unordered_set<int>& seen)
    {
        seen.insert(currNode);
        const auto& neighbors = hm.at(currNode);
        for (int neighbor : neighbors)
        {
            if (neighbor != prevNode)
            {
                if (seen.contains(neighbor))
                    return false; // loop found

                if (!helper(hm, neighbor, currNode, seen))
                    return false;
            }

        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges)
    {
        if (n == 0 && edges.size() == 0) return true;
        if (n == 1 && edges.size() == 0) return true;
        EdgeMap hm;

        for (const auto& vec : edges)
        {
            hm[vec.at(0)].insert(vec.at(1));
            hm[vec.at(1)].insert(vec.at(0));
        }

        int start = (*hm.begin()).first; // random node

        std::unordered_set<int> seen;

        if (!helper(hm, start, -1, seen)) return false;

        return seen.size() == n;
    }
};
