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

    void printList(ListNode* head)
    {
        while (head)
        {
            std::cout << head->val << " ";
            head = head->next;
        }

        std::cout << std::endl;
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
        
        halfway->next = reverseList(halfway->next);

        halfway = std::exchange(halfway->next, nullptr);

        std::cout << "LHS ";
        printList(head);
        std::cout << "\nRHS ";
        printList(halfway);
        std::cout << std::endl;

        // reverse second half

        ListNode* lhs = head;

        while (halfway)
        {
            ListNode* tempLhs = lhs->next;
            ListNode* tempRhs = halfway->next;

            lhs->next = halfway;
            halfway->next = tempLhs;

            lhs = tempLhs;
            halfway = tempRhs;

            printList(head);
        }
    }
};


/*

two pointer

[0, 1, 2, 3, 4, 5, 6]

[0, 1, 2, 3, 6, 5, 4]

[0, 6, 1, 5, 2, 4, 3]

*/