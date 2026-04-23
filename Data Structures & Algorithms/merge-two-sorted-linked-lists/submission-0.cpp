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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head = nullptr;
        ListNode* currA = list1;
        ListNode* currB = list2;

        ListNode* tail = nullptr;

        auto push = [&](int val)
        {
            if (!head)
            {
                head = new ListNode{val};
                tail = head;
            }
            else
            {
                tail->next = new ListNode{val};
                tail = tail->next;
            }
        };

        while (currA || currB)
        {
            if (currA && currB)
            {
                if (currA->val <= currB->val)
                {
                    push(currA->val);
                    currA = currA->next;
                }
                else // B < A
                {
                    push(currB->val);
                    currB = currB->next;
                }
            }
            else if (currA)
            {
                push(currA->val);
                currA = currA->next;
            }
            else if (currB)
            {
                push(currB->val);
                currB = currB->next;
            }
        }

        return head;
    }
};

/*

go through both lists, add the smaller element each time while they both have elements
deep copy each node; no short circuiting when one list becomes empty

return head of the new list


something like this:

function:
    head = nullptr
    currA = list1
    currB = list2
    currC = nullptr

    while currA or currB is non null:

        if currA and currB:
                add min of currA val and currB val
                min val node goes to next

        if only currA:
            add currA 
        if only currB:
            add currB

    return head

to add: if head is null, head = new Node{val}, else head next is new Node{val}

1-2-4
1-3-5

1-1 2-3 4-5

1-2-4-6
2-3-5

1 2-2 3-4 5-6


*/