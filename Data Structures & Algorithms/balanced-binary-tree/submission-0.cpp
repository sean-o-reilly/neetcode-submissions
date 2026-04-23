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
    int _height(TreeNode* curr, int currHeight)
    {
        if (!curr) return currHeight;
        ++currHeight;
        return std::max(_height(curr->left, currHeight), _height(curr->right, currHeight));
    }

    bool _isNodeBalanced(TreeNode* curr)
    {
        int difference = std::abs(_height(curr->left, -1) - _height(curr->right, -1));
        std::cout << "Balance check: " << curr->val << "\t Difference = " << difference << std::endl;
        return difference <= 1;
    }

    bool isBalanced(TreeNode* root)
    {
        if (!root) return true;

        if (!_isNodeBalanced(root)) return false;

        if (!isBalanced(root->left) || !isBalanced(root->right)) return false;

        return _isNodeBalanced(root);
    }
};

/*

First thing I would think of is going through each node 
and check to see if the heights of its children differ by no
more than 1.

Would prob be best to do this in post-order. Problem could be found 
at children sooner. We want to search bottom to top effectively.

Height of a null child could be -1.

Avoid checking subtrees reduntantly.

Post order would see one "process" per node


solution psuedocode:

bool function isBalanced: 
    base case:
        if curr is null, return -1

    recursive case:
        return 

        if height of left child and right child have a 
        difference of 1 or less, this node is balanced




*/