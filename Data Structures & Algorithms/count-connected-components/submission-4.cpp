class Solution {
public:
    void dfs(int curr, std::unordered_map<int, std::vector<int>>& graph, std::unordered_set<int>& seen)
    {
        if (seen.count(curr))
        {
            return;
        }
        else
        {
            seen.insert(curr);
        }

        for (int neighborNode : graph.at(curr))
        {
            dfs(neighborNode, graph, seen);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges)
    {
        std::unordered_map<int, std::vector<int>> graph; // node->neighbors of node
        std::unordered_set<int> seen; // seen nodes

        for (std::vector<int>& edge : edges)
        {
            int a = edge[0];
            int b = edge[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        } // all nodes and mappings are mapped, except for island nodes

        int components = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!graph.count(i))
            {
                ++components;
            }
        }


        for (auto [node, _] : graph)
        {
            if (!seen.count(node))
            {
                ++components;
                dfs(node, graph, seen);
            }
        }

        return components;
    }
};

/*

DFS islands problem


Psuedocode:

    main:
        build edges map: node->container of neighbors

        seen container

        islands = 0

        For each edge
            If edge is not seen,
                run dfs
                ++islands

        return 0

    dfs:
        if edge in seen, return
        else mark this as seen

        traverse all neighbors by calling dfs

*/