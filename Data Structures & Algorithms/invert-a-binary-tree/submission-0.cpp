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

 //  invertNode()
    // for each node in the tree
    //     temp = left
    //     left = right
    //     right = temp
    //     (or swap)
    //  invertNode(left)
    //  invertNode(right)


class Solution {
public:
    void invertNode(TreeNode* curr)
    {
        if (!curr) return;

        std::swap(curr->left, curr->right);
        invertNode(curr->left);
        invertNode(curr->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        invertNode(root);
        return root;
    }
};
