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
    bool isSameTree(TreeNode* A, TreeNode* B)
    {
        if (!A && !B) return true; // base case: search for inequality ended

        if ((A == nullptr) != (B == nullptr)) return false;

        if (A->val != B->val) return false;

        return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }

    bool isSubtree(TreeNode* curr, TreeNode* subRoot)
    {
        // traverese tree until root value == subRoot val, when it does, return isSameTree
        if (!curr || !subRoot) return false;

        if (curr->val == subRoot->val)
        {
            if (isSameTree(curr, subRoot)) return true;
        }

        return isSubtree(curr->left, subRoot) || isSubtree(curr->right, subRoot);
    }
};
