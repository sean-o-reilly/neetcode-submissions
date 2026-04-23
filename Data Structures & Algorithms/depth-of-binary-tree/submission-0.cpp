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

    void helper(TreeNode* curr, int currDepth, int& max)
    {
        if (!curr) return;

        max = std::max(currDepth, max);

        helper(curr->left, currDepth + 1, max);
        helper(curr->right, currDepth + 1, max);
    }

    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;

        int max = 1;
        helper(root, 1, max);
        return max;
    }
};

/*
We can use recursive traversal
Go down levels of the tree in any order traversal
we can increment out depth on each recursive step, and then increment a max global variable when appropriate
base case: stop recursively searching on a nullptr 

For example
start on 1 (depth = 0)
    go left to 2
    go right to 3
2 (depth = 1's depth + 1, so current depth is 1)
    go left to nullptr end search
    go right to nullptr end search
3 (depth = 1)
    go left to 4
    go right to nullptr, end search
4 (depth = 3's + 1, so depth here is 2)
    go left to nullptr
    go right to nullptr


pseudocode
    void helper(node curr, int currDepth, int& max)
        base: if curr is null, end search

        recursive:
            max = max(currDepth, max)

            helper(left, currDepth + 1, max)
            helper(right, currDepth + 1, max)

    maxDepth(root)
        int max = 0
        helper(root, 0, max)

        return max

    O(n) time, O(1) space

*/
