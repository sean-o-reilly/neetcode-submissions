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



//     1 
//   3   2
//  4   5  7
//     6    9
//         8

// algo to find the depth of left + depth of the right
// recursively call this algo for every node of the tree and take the max each call 

class Solution {
public:
    int depth(TreeNode* curr, int currDepth) const
    {
        if (!curr) return currDepth - 1;
        return std::max(depth(curr->left, currDepth + 1), depth(curr->right, currDepth + 1));
    } 

    void _diameter(TreeNode* curr, int currDepth, int& maxDiameter)
    {
        if (!curr) return;

        const int currDiameter = depth(curr->left, 1) + depth(curr->right, 1);
        maxDiameter = std::max(currDiameter, maxDiameter);

        _diameter(curr->left, currDepth + 1, maxDiameter);
        _diameter(curr->right, currDepth + 1, maxDiameter);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        _diameter(root, 1, maxDiameter);
        return maxDiameter;
    }
};
