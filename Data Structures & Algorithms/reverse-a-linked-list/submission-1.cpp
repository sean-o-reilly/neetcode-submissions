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
    constexpr ListNode* reverseList(ListNode* head) 
    {
        ListNode* prev = nullptr;
        while (head) prev = std::exchange(head, std::exchange(head->next, prev));
        return prev;
    }
};

/*

Using exchange, 
    while head
        set prev to head, set head to head->next, set head->next to previous

*/


/*

prev pointer

temp = curr-next # save next
curr-next = prev # point backwards

prev = curr # save to prev
curr = temp # move to next

do this until curr is null, return previous

*/