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
    // from reverse linked list II
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        int pos = 1;
        ListNode* curr = head;
        ListNode* leftBound = nullptr;

        while (pos < left)
        {
            leftBound = curr;
            curr = curr->next;
            ++pos;
        }

        ListNode* leftPtr = curr;

        while (pos < right)
        {
            curr = curr->next;
            ++pos;
        }

        ListNode* rightPtr = curr;
        ListNode* rightBound = rightPtr->next;

        curr = leftPtr;
        ListNode* prev = nullptr;

        while (curr != rightBound)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        leftPtr->next = rightBound;
        ListNode* reverseHead = rightPtr;

        if (leftBound)
        {
            leftBound->next = reverseHead;
            return head;
        }
        else
        {
            return reverseHead;
        }

        throw std::logic_error("?");
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int size = 0;
        ListNode* curr = head;
        while (curr)
        {
            curr = curr->next;
            ++size;
        }
        
        int start = 1;
        int end = k;
        while (end <= size)
        {
            head = reverseBetween(head, start, end);
            start += k;
            end += k;
        }
        return head;
    }
};
