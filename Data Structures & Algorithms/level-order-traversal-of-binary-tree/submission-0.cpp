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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if (!root) return {};

        vector<vector<int>> res;

        queue<TreeNode*> que;
        que.push(root);

        while (que.size())
        {
            vector<TreeNode*> level;
            vector<int> group;

            while (que.size()) // create grouping by level
            {
                TreeNode* curr = que.front();
                level.push_back(curr);
                group.push_back(curr->val);     
                que.pop();
            }

            for (TreeNode* node : level) //push children
            {
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            res.push_back(group); // [1], [2, 3], []
        }

        return res;
    }
};

// loop until queue is empty
//  pop all elements from the queue, put them in a group vector
//  for each node in the group vector, add its children to the queue

// level order traversal = bfs

// level order traversal
//  queue
//  starting at head
//  add head to queue

// while queue has nodes,
//  curr = queue.pop
//  add curr left and right to queue

// how to divide into levels?

// check after popping, is the queue empty? (before while condition is checked)
// if it is, pushback all the elements in this level

// write a function to check height of a node
//      when height does not equal last height we had, make a new container to add to res. this allows groupings

// 1, height = 2
// [1]
// 2, height = 1, different, so make new group
// [1], [2]
// 3, height = 1, same, so push to last group
// [1], [2, 3]
// 4, height = 0, differemt add new group
// [1], [2, 3], [4]
// 5, height = 0, same, push to last group
// 6..
// 7.. push to last
// [1], [2, 3], [4,5,6,7]

// n = nodes
// h = height
// O(n * log(h))

// func
// add root to the queue
// loop until queue is empty
//  pop all elements from the queue, put them in a group vector
//  for each node in the group vector, add its children to the queue

// 1
// [1], 2 3 in queue
// [1], [2, 3], 4, 5, 6, 7 in queue
// [1], [2, 3,], [4, 5, 6, 7], null children in empty queue. queue empty, break
