/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    static constexpr char nullNode = 'x';

    // Encodes a tree to a single string.
    void _serialize(TreeNode* curr, std::vector<TreeNode*>& nodes)
    {
        nodes.push_back(curr);
        if (!curr) return;
        _serialize(curr->left, nodes);
        _serialize(curr->right, nodes);
    }

    string serialize(TreeNode* root)
    {
        if (!root) return "";

        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<TreeNode*> nodes;
        _serialize(root, nodes);

        std::ostringstream oss;        

        for (TreeNode* node : nodes)
            node ? oss << node->val << "," : oss << nullNode << ",";

        std::cerr << oss.str() << std::endl;

        return oss.str();
    }

    // Decodes your encoded data to tree.
    std::pair<TreeNode*, int> _deserialize(const std::vector<std::optional<int>>& data, int idx)
    {
        TreeNode* curr = new TreeNode(data.at(idx).value());

        int leftIdx = idx + 1;
        int rightIdx = idx + 2;

        if (data.at(leftIdx).has_value()) // solve left subtree
        {
            std::cerr << data.at(idx).value() << "'s left is " << data.at(leftIdx).value() << std::endl;
            auto p = _deserialize(data, leftIdx);
            curr->left = p.first;
            rightIdx = p.second + 1;
        }
        else std::cerr << data.at(idx).value() << "'s left is null" << std::endl;

        if (data.at(rightIdx).has_value()) // solve right subtree
        {
            std::cerr << data.at(idx).value() - '0' << "'s right is " << data.at(rightIdx).value() << std::endl;
            auto p = _deserialize(data, rightIdx);
            curr->right = p.first;
            rightIdx = p.second;
        }
        else std::cerr << data.at(idx).value() << "'s right is null" << std::endl;

        return {curr, rightIdx};
    }

    TreeNode* deserialize(string data)
    {
        if (data.empty()) return nullptr;

        std::vector<std::optional<int>> vals;
        std::stringstream ss(data);
        std::string token;
        
        while (std::getline(ss, token, ','))
        {
            if (token == "x")
            {
                vals.push_back(std::nullopt);
            }
            else vals.push_back(std::stoi(token));
        }
        
        for (auto n : vals)
        {
            if (n.has_value())
            {
                std::cerr << n.value() << " ";
            }
            else
            {
                std::cerr << "x ";
            }
        }
        std::cerr << std::endl;

        return _deserialize(vals, 0).first;
    }
};

/*
serialize:

level order traversal using a queue
push null nodes

at end, trim off any trailing null nodes entries

q = Queue()
nodes = []

q push tree's root

while q has elements:
    node = q pop
    q push (node->left, node->right)
    nodes.push back (q)

nodes now filled with all nodes and children

// TODO remove range
while (nodes back == nullptr)
    nodes pop back

create string from nodes
for node in nodes:
    if node is null
        string += "_"
    else 
        string += node->val to string

return string

*/


/*
deserialize:

left child = root index * 2 + 1
right child = root index * 2 + 2

pre order traversal (parent, left, right)

recursive(idx, data&):
    if idx out of bounds, or at(idx) is null, or data empty, return nullptr

    curr = new Node(data at (idx))

    curr -> left = recursive(idx * 2 + 1)
    curr -> right = recursive(idx * 2 + 2)
    
    return curr
*/