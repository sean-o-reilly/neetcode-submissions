/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) 
    {
        if (!head) return false;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr)
        {
            if (slow == fast) return true;

            slow = slow->next;
            
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
        }

        return false;
    }
};


/*

Start with a slow and fast pointer

slow pointer is incremented by one "step"
fast pointer is increment by two steps
fast starts on second node

we can loop until fast hits nullptr 
    make sure to not read nullptr though, so include a null check!

if slow and fast ever equal each other, a cycle happened.
they will eventually overlap

*/