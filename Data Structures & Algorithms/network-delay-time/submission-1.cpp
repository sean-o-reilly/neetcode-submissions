class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        using P = std::pair<int,int>;

        auto cmp = [](const std::pair<int, int> A, const std::pair<int, int> B)
        {
            return A.second > B.second;
        };

        std::priority_queue<P, std::vector<P>, decltype(cmp)> pq(cmp);
        std::unordered_map<int, int> distances; 
        std::unordered_set<int> visited;

        for (int i = 1; i <= n; ++i) // initialize all node distances to inf
        {
            distances[i] = std::numeric_limits<int>::max();
        }

        pq.push({k, 0});

        while (pq.size()) // djikstra's
        {
            std::pair<int, int> curr = pq.top();
            pq.pop();

            const int node = curr.first;

            if (visited.count(node))
            {
                std::cout << node << " already visited" << std::endl;
            }
            else
            {
                visited.insert(node);
                int currDistance = curr.second;

                distances[node] = std::min(distances[node], currDistance); // update distance with new shortest

                // insert children in pq

                for (auto& edge : times)
                {
                    if (edge[0] == node) // we are at an edge of this curr node
                    {
                        int target = edge[1];
                        int timeWeight = edge[2];
                        pq.push({target, currDistance + timeWeight}); // push relative to our current distance
                    } 
                } 
            }
        }

        std::cout << "Result:" << std::endl;

        for (auto& [key, value] : distances)
        {
            std::cout << key << " in " << value << "s" << std::endl;
        }

        if (visited.size() != n) // not all nodes were visited
        {
            return -1;
        }

        int maxDist = -1;
        for (auto [key, value] : distances)
        {
            maxDist = std::max(maxDist, value);
        }

        return maxDist; // time it took for all nodes to be reached
    }
};

// n nodes, labeled 1-n
// times: list of directed edges. times[i] = 

// k = starting node

// times[i] = source node, target node, time it takes to go from source->target

// djikstra's algorithm


// ALGORITHM
// start by adding starting node to pq
// while pq has nodes:
// curr = pq.pop
//  if curr already visited: skip processing
//  else add curr to visited
//
//  update map with distance of this node from source. = min(currDistance, distance)
//  process: add all children to pq with child distance (curr distance + distance from curr)

// use inf or max for unseen values

// if visited size != n, we didn't reach all nodes, return -1
// else return max value in map

// distance map
// 1: inf
// 2: 0
// 3: 1

// visited 2, 3
// pq 