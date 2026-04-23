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
            std::cout << curr->val << " not less than " << rootVal << std::endl;
            return false;
        }

        return lessThanRoot(curr->left, rootVal) && lessThanRoot(curr->right, rootVal);
    }

    bool greaterThanRoot(TreeNode* curr, int rootVal)
    {
        if (!curr) return true;
        if (curr->val <= rootVal)
        {
            std::cout << curr->val << " not greater than " << rootVal << std::endl;
            return false;
        }

        return greaterThanRoot(curr->left, rootVal) && greaterThanRoot(curr->right, rootVal);
    }

    bool isValidBSTHelper(TreeNode* subroot, std::unordered_map<TreeNode*, bool>& cache)
    {
        if (!subroot) return true;

        if (cache.count(subroot)) return cache.at(subroot);

        if (!lessThanRoot(subroot->left, subroot->val) || !greaterThanRoot(subroot->right, subroot->val))
        {
            std::cout << "Ret false at " << subroot->val << std::endl;
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
