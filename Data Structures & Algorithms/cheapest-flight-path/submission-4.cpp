class Solution
{
public:
    struct Node
    {
        int ID;
        int distance;
        int kDistance;
    };

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        using Pair = std::pair<int, int>; // Node ID, neighbor distance
        std::unordered_map<int, std::vector<Pair>> edges;

        for (std::vector<int>& edge : flights)
        {
            edges[edge[0]].push_back({edge[1], edge[2]});
        }

        for (auto [start, neighbors] : edges)
        {
            for (auto neighbor : neighbors)
            {
                std::cout << start << " -> " << neighbor.first << ", " << neighbor.second << std::endl;
            }
        }

        auto cmp = [](Node& A, Node& B)
        {
            return A.distance > B.distance;
        };

        std::priority_queue<Node, std::vector<Node>, decltype(cmp)> pq(cmp);

        pq.push(Node{src, 0, 0});

        while (!pq.empty())
        {
            Node curr = pq.top();
            pq.pop();

            if (curr.ID == dst)
            {
                std::cout << curr.ID << " found after " << curr.kDistance -  1 << " stops" << std::endl;
                return curr.distance;
            }

            int neighborK = curr.kDistance + 1;

            if (!edges.count(curr.ID))
            {
                edges[curr.ID] = {};
            }

            for (Pair neighbor : edges.at(curr.ID)) // traverse curr's neighbors
            {
                if (neighbor.first == dst || neighborK <= k)
                {
                    pq.push(Node{neighbor.first,
                    curr.distance + neighbor.second,
                    neighborK});
                }
            }
        }

        return -1;
    }
};


/*


Pseudocode:

    djikstras
        priority queue pq: sorted by comparison  decltype () lambda
        edges map: node -> container of neighbors and cost to reach

        build map of edges
            for edge in flights
            map at start:
                insert to container destination, weight

        add start node to pq, distance 0, k=0

        while pq has nodes:
    
            curr = pop top of pq

            if curr is dst, return curr distance

            for neighbor of curr:
                pq push neighbor, 
                    neighbor distance + curr distance,
                    k distance (only if k distance <= k, or is dst)

        none found, return -1

Djikstra's or DFS


Djikstras:
    Take locally cheapest next option at every node

    Don't forget to add the cost of previous nodes when traversing

    K twist:
        can only go to nodes that can be reached in k stops or less
            unless node is end node


Will need a way to traverse the vector graph


A - 100 - B - 100 - C - 100 - D    - 100 - F
  \                                        /
    \ ------------------ 200 --- E -- 100 /


*/
