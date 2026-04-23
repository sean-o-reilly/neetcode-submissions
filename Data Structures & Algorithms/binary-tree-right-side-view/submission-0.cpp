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

class Solution {
public:
    void printTree(TreeNode* curr)
    {
        if (curr)
        {
            std::cout << curr->val << std::endl;
            printTree(curr->left);
            printTree(curr->right);
        }
    }

    vector<int> rightSideView(TreeNode* root)
    {
        if (!root) return {};

        std::vector<int> rightmost{root->val};

        std::queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            std::vector<TreeNode*> children;

            while (!q.empty())
            {
                TreeNode* curr = q.front();
                q.pop();
                std::cout << curr->val << " ";
                if (curr->left) children.push_back(curr->left);
                if (curr->right) children.push_back(curr->right);
            }

            for (TreeNode* child : children) q.push(child);

            if (!children.empty()) rightmost.push_back(children.back()->val);

            std::cout << std::endl;
        }


        return rightmost;
    }
};


/*

Level order traversal
    Take rightmost element on each level

*/
