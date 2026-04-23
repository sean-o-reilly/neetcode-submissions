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
    void _inorder(TreeNode* curr, std::vector<int>& vec)
    {
        // left, curr, right
        if (curr == nullptr) return;
        _inorder(curr->left, vec);
        vec.push_back(curr->val);
        _inorder(curr->right, vec);
    }

    vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> vec;
        _inorder(root, vec);
        return vec;
    }
};