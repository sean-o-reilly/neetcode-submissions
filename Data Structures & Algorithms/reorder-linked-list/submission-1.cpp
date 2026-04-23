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

#include <utility>

class Solution {
public:
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        while (head) prev = std::exchange(head, std::exchange(head->next, prev));
        return prev;
    }

    void reorderList(ListNode* head)
    {
        ListNode* halfway = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            halfway = halfway->next;
            fast = fast->next->next;
        }
        halfway = std::exchange(halfway->next, nullptr); // cut into two pieces and reverse
        halfway = reverseList(halfway);
        while (halfway) head = std::exchange(head->next, std::exchange(halfway, std::exchange(halfway->next, head->next)));
    }
};


/*

two pointer

[0, 1, 2, 3, 4, 5, 6]

[0, 1, 2, 3, 6, 5, 4]

[0, 6, 1, 5, 2, 4, 3]

*/