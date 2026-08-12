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
#include <iostream>
#include <generator>
#include <ranges>
#include <print>

class Solution {
public:
    std::generator<int> InOrder(TreeNode* root)
    {
        if (!root)
        {
            co_return;
        }
        
        co_yield std::ranges::elements_of(InOrder(root->left));
        co_yield root->val;
        co_yield std::ranges::elements_of(InOrder(root->right));
    }    

    vector<int> inorderTraversal(TreeNode* root)
    {
        return InOrder(root) | std::ranges::to<std::vector>();
    }
};