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

    bool lessThanRoot(TreeNode* curr, int rootVal)
    {
        if (!curr) return true;

        if (curr->val >= rootVal)
        {
            return false;
        }

        return lessThanRoot(curr->left, rootVal) && lessThanRoot(curr->right, rootVal);
    }

    bool greaterThanRoot(TreeNode* curr, int rootVal)
    {
        if (!curr) return true;
        if (curr->val <= rootVal)
        {
            return false;
        }

        return greaterThanRoot(curr->left, rootVal) && greaterThanRoot(curr->right, rootVal);
    }

    bool isValidBSTHelper(TreeNode* subroot, std::unordered_map<TreeNode*, bool>& cache)
    {
        if (!subroot) return true;

        if (cache.count(subroot)) 
        {
            static int cachehits;
            ++cachehits;
            std::cout << cachehits << std::endl;
            return cache.at(subroot);
        }

        if (!lessThanRoot(subroot->left, subroot->val) || !greaterThanRoot(subroot->right, subroot->val))
        {
            return false;
        }

        bool res = isValidBSTHelper(subroot->left, cache) && isValidBSTHelper(subroot->right, cache);

        cache.insert({subroot, res});

        return res;
    }

    bool isValidBST(TreeNode* root)
    {
        std::unordered_map<TreeNode*, bool> cache;
        return isValidBSTHelper(root, cache);
    }
};
