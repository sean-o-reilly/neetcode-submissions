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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root, low, high, sum);

        return sum;
    }

    void helper(TreeNode* curr, int low, int high, int& sum)
    {
        if (!curr)
            return;
        
        helper(curr->left, low, high, sum);
        if (curr->val >= low && curr->val <= high)
            sum += curr->val;
        helper(curr->right, low, high, sum);
    }
};

/*
In order traversal, incrementing sum for nodes in range

*/