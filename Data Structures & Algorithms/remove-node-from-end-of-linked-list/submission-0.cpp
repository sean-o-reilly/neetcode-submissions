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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (!head->next) // size == 1
        {
            delete head;
            return nullptr;
        }

        ListNode* curr = head;
        int size = 0;
        while (curr)
        {
            curr = curr->next;
            ++size;
        }

        if (n == size)
        {
            ListNode* res = head->next;
            delete head;
            return res;
        }

        curr = head;

        for (int i = 1; i < size - n; ++i)
        {
            curr = curr->next;
        }

        if (!curr) throw std::logic_error("???");

        if (curr->next)
        {
            ListNode* temp = curr->next->next;
            delete curr->next;
            curr->next = temp; // TODO leak deleted node
        }

        return head;
    }
};

/*

O(n) space -> create container of nodes while traversing, index into nth index from end
    then run a O(1) time middle of LL removal

O(1) space
    no container
    no recursive stack

    maybe slow fast pointer? 
        slow pointer will stop at the halfway point?
        having the size would be helpful

        why not just traverse list, store count of nodes in a integer, then remove nTh that way

*/