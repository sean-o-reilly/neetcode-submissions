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

    bool isValidBST(TreeNode* root)
    {
        if (!root) return true;

        if (!lessThanRoot(root->left, root->val) || !greaterThanRoot(root->right, root->val))
        {
            std::cout << "Ret false at " << root->val << std::endl;
            return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};
