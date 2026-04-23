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
    bool isSameTree(TreeNode* A, TreeNode* B) const
    {
        if (!A && !B)
        {
            return true; // base case: search ends
        }

        if ((A == nullptr) != (B == nullptr)) return false; // one is null and one isn't

        if (A->val != B->val) return false;

        return isSameTree(A->left, B->left) && isSameTree(A->right, B->right);
    }
};

/*

same if same structure and same value

we'd have to check if 1 is the same, and then if 1's left is the same, and if 1's right is the same, and if 1's left's left is the same, so recursive in nature

function:
    base case: both are null. return true

    recursive step: structure check first
        if A is null but B isn't, return false
        if B is null and A isn't, return false

    we have two values, check if they are equal
        if A value != B value, return false

    if we passed all these checks, the nodes are the same, but are their children the same?

    return (A left same as B left) && (A right same as B right)
*/