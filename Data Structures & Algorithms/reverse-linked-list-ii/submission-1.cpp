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
};


/*

0-1-2-3-4-5
left = 3
right = 4
reverse 2-3
0-1-3-2-4-5

- position pointers
- reverse list within window
- repair list

pos = 1
curr = head
leftBound = null

while pos < left
    leftBound = curr
    curr = curr->next
    ++pos
left = curr

while pos < right
    curr = curr->next
    ++pos
right = curr
rightBound = right next // after reversing, set as head's next


// reverse starting at left
curr = left
prev = curr

while curr != rightBound
    temp = curr->next
    curr->next = prev
    curr = temp
    // or curr = std::exchange(curr->next, prev)

// repair and return

left->next = rightBound

reverseHead = right
    if leftBound non null,
        leftBound next = reverseHead
        return head
    else
        return reverseHead
    


*/