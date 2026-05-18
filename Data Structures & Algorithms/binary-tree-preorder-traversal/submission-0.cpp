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
    std::vector<int> res_;

    void helper_(TreeNode* curr)
    {
        // curr, left, right
        if (!curr) return;
        res_.push_back(curr->val);
        helper_(curr->left);
        helper_(curr->right);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        helper_(root);
        return res_;
    }
};