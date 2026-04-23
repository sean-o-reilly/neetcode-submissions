/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head)
    {
        if (!head) return {};
        
        std::vector<Node*> oldList;
        std::unordered_map<Node*, int> oldIdx;

        std::vector<Node*> newList;
        std::unordered_map<Node*, int> newIdx;

        Node* curr = head;

        int idx = 0;
        while (curr) // deep copy list in order without nexts or randoms
        {
            oldList.push_back(curr);
            oldIdx[curr] = idx;

            Node* newNode = new Node(curr->val);
            newList.push_back(newNode);
            newIdx[newNode] = idx;

            curr = curr->next;
            ++idx;
        }

        {
            for (Node* node : oldList)
            {
                std::cout << node->val << " ";
            }
            std::cout << "\n";
            for (Node* node : newList)
            {
                std::cout << node->val << " ";
            }
            std::cout << "\n";
        }


        for (int i = 0; i < newList.size(); ++i)
        {
            Node* oldCurr = oldList.at(i);
            if (oldCurr->random)
            {
                int oldRandIdx = oldIdx.at(oldCurr->random);
                std::cout << oldCurr->val << " points to index " << oldRandIdx << std::endl;
                newList.at(i)->random = newList.at(oldRandIdx);
            }
            // nullptr?

            if (i + 1 < newList.size()) newList.at(i)->next = newList.at(i + 1);
        }

        return newList.at(0);
    }
};

// hashset can track used/seen pointer values
// hashmap can also help
//      shallow/original copy -> new instance pointer

// array may help
/*

0 indexed array of old pointers
0 indexed array of new pointers





*/