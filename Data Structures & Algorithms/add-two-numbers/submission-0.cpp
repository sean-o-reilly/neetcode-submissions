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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode* sumList = nullptr;
        ListNode* head = nullptr;

        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;

            int sum = val1 + val2 + carry;

            carry = (sum >= 10);
            sum %= 10;

            if (!sumList)
            {
                sumList = new ListNode(sum);
                head = sumList;
            }
            else
            {
                sumList->next = new ListNode(sum);
                sumList = sumList->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return head;
    }
};

/*
int carry = 0
sumList = linked list
while (l1 or l2 is not null OR carry == 1)
    # deref ptrs
    if l1 nonull, l1Val = l1->val, else 0
    if l2 nonnull, l2Val = l2->val, else 0

    sum = l1Val + l2Val + carry

    carry = (sum >= 10)
    sum %= 10
    
    sumList.push_back (sum)
*/

/*
[1, 2, 3]
[4, 5, 6]
[5, 7, 9]

[9]
[9]
[8, 1]

[0]
[0]
[0]

[9, 9, 9, 9]
[1]
when overflow, take mod 10 to get remainder
leave remainder in curr node, carry a 1 to next node (create if doesn't exist)
9 + 1 = 10
10 % 10 = 0
[0] -> carry 1
[0, 0, 0, 0, 1]

[9]
[1]
[0, 1]

[9, 9, 9]
[9, 9, 9]
[8, 9, 9, 1]

*/

