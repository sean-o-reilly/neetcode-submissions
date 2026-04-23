/*
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    void printGraph(Node* node)
    {
        std::queue<Node*> q;
        q.push(node);
        std::unordered_set<Node*> seen;

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            seen.insert(curr);

            std::cout << curr->val << " ";

            for (Node* neighbor : curr->neighbors)
            {
                if (!seen.count(neighbor)) q.push(neighbor);
            }
        }
        std::cout << "\n";
    }

    std::unordered_set<Node*> getNodes(Node* node)
    {
        std::queue<Node*> q;
        q.push(node);
        std::unordered_set<Node*> res;

        while (!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            res.insert(curr);

            for (Node* neighbor : curr->neighbors)
            {
                if (!res.count(neighbor)) q.push(neighbor);
            }
        }
        
        return res;
    }

    Node* cloneGraph(Node* node)
    {
        if (!node) return nullptr;

        std::unordered_map<Node*, Node*> oldNew;
        std::unordered_set<Node*> nodes = getNodes(node);

        for (Node* node : nodes)
        {
            Node* deepCopyNode = new Node(node->val);
            oldNew.insert({node, deepCopyNode}); // create deep copies with empty neighbors
        }

        for (auto [oldNode, newNode] : oldNew)
        {
            // for each new Node, use oldNode's neighbor list
            //  for each neighbor in that list, add that neighbor's new equivalent to the newNode's neighbor list using the oldNew map

            for (Node* neighbor : oldNode->neighbors)
            {
                Node* newNeighbor = oldNew.at(neighbor);
                newNode->neighbors.push_back(newNeighbor);
            }
        }

        // auto dummy = new Node(67);
        return oldNew.at(node);
    }
};

/*

Map old memory address to new ones

Need:
    New copy
    Mapping of neighbors
    Value


*/
