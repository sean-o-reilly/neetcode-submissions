class Solution {
public:
    struct Node
    {
        std::unordered_set<int> incoming;
        std::unordered_set<int> outgoing;
    };

    int findJudge(int n, vector<vector<int>>& trust)
    {
        std::unordered_map<int, Node> hm;

        for (const auto& vec : trust)
        {
            int a = vec.at(0);
            int b = vec.at(1);

            hm[a].outgoing.insert(b);
            hm[b].incoming.insert(a);
        }

        for (const auto& [id, node] : hm)
        {
            if (node.outgoing.size() == 0 && node.incoming.size() == n - 1)
            {
                return id;
            }
        }

        return -1;
    }
};