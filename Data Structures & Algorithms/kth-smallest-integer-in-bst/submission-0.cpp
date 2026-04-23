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
    void inOrderTraversal(TreeNode* curr, int& nodesTraversed, int& kth, int k)
    {
        if (!curr) return;

        inOrderTraversal(curr->left, nodesTraversed, kth, k);

        if (++nodesTraversed == k)
        {
            kth = curr->val;
            return;
        }

        inOrderTraversal(curr->right, nodesTraversed, kth, k);
    }

    int kthSmallest(TreeNode* root, int k)
    {
        int nodesTraversed = 0;
        int kthSmallestNum = -1;
        inOrderTraversal(root, nodesTraversed, kthSmallestNum, k);
        return kthSmallestNum;
    }
};


/*

To find smallest:
    Take left-most node
        Go left until there is no more left node

    Least to greatest traversal: (in order)

        if left, process left
        process curr
        if right, process right


*/