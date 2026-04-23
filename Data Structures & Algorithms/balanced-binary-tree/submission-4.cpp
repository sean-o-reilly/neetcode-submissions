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
    // post order traversal is the key to O(n). It eliminates the need for redundant calculations

    using Pair = std::pair<bool, int>;

    Pair helper(TreeNode* curr)
    {
        if (!curr) // base case
        {
            return {true, 0};
        }

        //check left
        Pair left = helper(curr->left);
        if (!left.first) return {false, -1};
        
        //check right
        Pair right = helper(curr->right);
        if (!right.first) return {false, -1};

        //check curr
        bool currBalanced = std::abs(left.second - right.second) <= 1;
        int currHeight = std::max(left.second, right.second) + 1;

        return {currBalanced, currHeight};
    }

    bool isBalanced(TreeNode* root)
    {
        return helper(root).first;
    }
};

/*

Post order traversal to keep it O(n)

starting with root, check children

base case is: both children are null

once we reach the base case, we can return and let earlier parts of recursive search determine height balancing

        5
    3       10
  1  4        12
-1               14

starting with 5, we ask if this node is balanced
in order to know that, we must check its children first to be optimal
if at any point we find an un balanced node, return false

-1 has no children, return height 1
1's left has height 1, 1's right has height 0
3's left has height 2, (1 + 1), 3's right has height ?
at 4, we are a leaf so balanced with height of 1
3's left is within 1 height of its right, balanced
3 can return its max child height + 1               each node can return its max child height + 1 as its height. null nodes can return 0

5 needs to now check for right children
10->left = height of 0
10->right -> 12 -> 12's left is height of 0 -> 12's right -> 14 has height of 1
12 left = 0, 12 right = 1 so 12 is balanced. we can return max of children 1 + 1 from 12
10 know its left is height of 0, and its right is height of 2, 10 is unbalanced. only one calculation per node

pseudocode:

    func helper(node curr) returns bool balanced, int height
        base case: if curr is null, return true, 0

        check left
            left height, balanced = helper(left)
        check right
            right height, balanced = helper(right)

        is either node not balanced, return false

        check this
            if left height within 1 of right height, we are balanced

            this height is the max of left and right height, plus 1

        return this balanced, this height


    func isBalanced(node curr) returns bool
        return helper

*/