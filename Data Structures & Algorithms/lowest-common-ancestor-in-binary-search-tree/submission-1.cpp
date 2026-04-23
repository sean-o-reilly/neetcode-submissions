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
    bool preorder(TreeNode* curr, TreeNode* searchNode, vector<TreeNode*>& path)
    {
        //bases
        if (!curr) return false;

        if (curr == searchNode)
        {
            path.push_back(curr);
            return true;
        }

        //recursive
        if (preorder(curr->left, searchNode, path))
        {
            path.push_back(curr);
            return true;
        }
        else if (preorder(curr->right, searchNode, path))
        {
            path.push_back(curr);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<TreeNode*> pPath;
        std::vector<TreeNode*> qPath;

        preorder(root, p, pPath);
        preorder(root, q, qPath);

        int pIdx = pPath.size() - 1;
        int qIdx = qPath.size() - 1;

        TreeNode* lca = root;

        while (pIdx >= 0 && qIdx >= 0)
        {
            if (pPath.at(pIdx) == qPath.at(qIdx))
            {
                lca = pPath.at(pIdx);
                --pIdx;
                --qIdx;
            }
            else
            {
                return lca;
            }
        }

        return lca;
    }
};

/*

Start with node as the lowest

Traverse down the tree to find p and q in the same order, 

After finding them both, walk back up the tree via recursive unwinding and store new lowest

Store all parents of nodes when recursively walking up. When walking up, all nodes touched are parents

Case:

2, 4
2's parents bottom to top (inclusive): 2, 1, 3, 5
4's: 4, 3, 5

Find first match in these contains, return that result
time: O( logn * 2 + k ) where k is number of parents/levels down the p and q are


Pseudocode:

    // need a way to determine the "path" to a node
    bool preorder search(vector reference, node):
        base cases:
            if node is nullptr
                return false

            if node is the search node
                return true

        recursive case:
            if preorder search(node->left) returns true:
                vector push back node->left
                return true
            else if preorder search(node->right) returns true:
                vector push back node->right
                return true
            else
                return false

    call like so:
    vector<node>& path{root}
    preorderSearch(path, root)


    lca(root, p, q):
        vector pPath{root}
        vector qPath{root}

        preorder search for (pPath, root)
        preorder search for (pPath, root)

        the LCA is the first entry that is the same in both containers
        search back to front would yield correct order


2 1 3 5
4 3 5
search back to front, first mismatch index + 1 is the LCA here

7 8 5
9 8 5

*/