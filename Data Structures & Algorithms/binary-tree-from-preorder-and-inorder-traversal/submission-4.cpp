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

class Solution
{
public:
    using Map = std::unordered_map<int, int>;
    using Set = std::unordered_set<int>;

    TreeNode* dfs(TreeNode* root, Set& seen, Map& lrIdx, Map& rootIdx, std::vector<int>& inorder, std::vector<int>& preorder)
    {
        const int rootVal = root->val;
        const int rootInorderIdx = lrIdx[rootVal];

        int leftMinIdx = std::numeric_limits<int>::max();
        int rightMinIdx = std::numeric_limits<int>::max();
        
        for (int i = rootInorderIdx - 1; i >= 0; --i) // find leftmost preorder value, the left subtree root value
        {
            if (!seen.count(inorder[i]))
            {
                leftMinIdx = std::min(leftMinIdx, rootIdx[inorder[i]]);
                continue;
            }
            break;
        }

        if (leftMinIdx < inorder.size())
        {
            int leftSubTreeRootValue = preorder.at(leftMinIdx);
            seen.insert(leftSubTreeRootValue);
            root->left = dfs(new TreeNode(leftSubTreeRootValue), seen, lrIdx, rootIdx, inorder, preorder);
        }

        for (int i = lrIdx[rootVal] + 1; i < inorder.size(); ++i) // repeat for right subtree
        {
            if (!seen.count(inorder[i]))
            {
                rightMinIdx = std::min(rightMinIdx, rootIdx[inorder[i]]);
                continue;
            }
            break;
        }

        if (rightMinIdx < inorder.size())
        {
            int rightSubTreeRootValue = preorder.at(rightMinIdx);
            seen.insert(rightSubTreeRootValue);
            root->right = dfs(new TreeNode(rightSubTreeRootValue), seen, lrIdx, rootIdx, inorder, preorder);
        }

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        Map rootIdx;
        for (int i = 0; i < preorder.size(); ++i) rootIdx.insert({preorder[i], i});
        Map lrIdx;
        for (int i = 0; i < inorder.size(); ++i) lrIdx.insert({inorder[i], i});

        Set seen{preorder[0]};

        TreeNode* root = new TreeNode(preorder[0]);

        root = dfs(root, seen, lrIdx, rootIdx, inorder, preorder);

        return root;
    }
};

/*

using DFS hints:

    the root is the leftmost "valid" node in preorder
        its left subtree is all elements to its left
        its right substree is all elements to its right

        if it has no valid left or right elements, its a leaf and does nothing
        if it has 1 or more valid left or right elments, it has subtrees

            for both subtrees, their root is the whatever subtree value is leftmost
            in pre order. If the subtree contains 7, 3, 2, and 3 is leftmost, 3 is the subtree root

    left and right children = subtree root of left, subtree root of right
    what is the root of a subtree? for each node->left most node in preorder
    subtree root may be nothing / nullptr

recursive pseudocode:

    "curr" ptr
    left/right in inorder
    left subtree = all elements to root left that are not in seen
    right subtree = all elements to root right that is not in seen

    base case:
        if left and right subtree are empty
        return curr

    recursive case:
        curr's left subtree root = dfs(curr = left subtree's leftmost element in preorder)
        curr's right subtree root = dfs(curr = right subtree's leftmost element in preorder)

        return curr



*/


/*

preorder
    curr->left->right recursively


inorder
    left->curr->right recursively


reconstructed
    left child = pos * 2 + 1
    right child = pos * 2 + 2


info:

we cant tell if 4 is 3's left or right child
but we know its a child since it comes later in preorder
we can tell that 4 is to the right of 3 since it comes later in the inorder list
we can tell 2 is to the left of 1

if a number is in a higher index in the preorder list,
it is a children of one or more nodes to the left


the inorder list is the tree flattened, which preserves the left-right ordering,
    we can use this to determine which side children are on

example:

1 is the first node in preorder so we know its the root

2 is a child of 1 because the only number left of 2 in preorder is 1
2 is to the left of 1 in inorder, so it must be 1's left child

3 is to the left of 1 and 2, it is the child of one of these nodes
it can't be the child of 2, because we know 2 is to the left of 1 and 3 is to the right of 1
it must be the right child of 1 then


4 is to the left of 1, 2, and 3. It is the child of one of these nodes.
1 already has two confirmed children so its not 1
2 or 3 are potential parents

4 is to the right of 2, and to the right of 2's parent, 1, so it can't be 2's child
3 is the only potential parent left. 
4 is to the right of 3, so 4 must be 3's right child



*/