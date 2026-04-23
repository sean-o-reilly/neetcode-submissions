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
    void _goodHelper(TreeNode* curr, int currMax, int& goodCount)
    {
        if (!curr) return; // base

        //recursive
        if (curr->val >= currMax)
        {
            std::cout << curr->val << " is a good node" << std::endl;
            ++goodCount;
            currMax = curr->val;
        }

        _goodHelper(curr->left, currMax, goodCount);
        _goodHelper(curr->right, currMax, goodCount);
    }

    int goodNodes(TreeNode* root) 
    {
        int goodCount = 0;
        _goodHelper(root, std::numeric_limits<int>::min(), goodCount);

        return goodCount;
    }
};


// try storing a max value while traversing the tree

// at 2 (root), max is 0. Since 2 > 0, this is a good node. increment good. max = 2 now
// going to 2->left we get to 1
// 2 is the max, 1 is less than 2, so this node is not good
// going to 1->left 
// 3 is greater than the max. max = 2, increment good
// going to 3->left. null
// 3->right. null
// 1->right. null
// 2->right is 1
// 1 is less than the max, 2.
// go to 1->left
// 1 is less than the max, 2
// 1->left and right are null
// go to 1->right
// 5 is greater than the max, 2. increment good

// recursive function
// void _goodHelper(currNode, currMax, &goodCount)

// to start: _goodHelper(root, 0, goodCount)
// base case is curr == null
// recursive case: call _goodHelper with curr left and right, as well as the running max
