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
    ListNode* mergeTwo(ListNode* left, ListNode* right)
    {
        if (!left) return right;
        if (!right) return left;

        ListNode* head = nullptr;

        if (left->val <= right->val)
        {
            head = left;
            left = left->next;
        }
        else
        {
            head = right;
            right = right->next;
        }

        ListNode* tail = head;

        while (left || right)
        {
            if (left && right)
            {
                if (left->val <= right->val)
                {
                    tail->next = left;
    
                    left = left->next;
                    tail = tail->next;
                }
                else 
                {
                    tail->next = right;

                    right = right->next;
                    tail = tail->next;
                }
            }
            else if (!left)
            {
                tail->next = right;
                break;
            }
            else if (!right)
            {
                tail->next = left;
                break;
            }
        }
        return head;
    }

    void printList(ListNode* ls)
    {
        ListNode* curr = ls;
        while (curr)
        {
            std::cerr << curr->val << " ";
            curr = curr->next;
        }
        std::cerr << std::endl;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        std::deque<ListNode*> q(lists.begin(), lists.end());

        while (q.size() > 1)
        {
            ListNode* left = q.front();
            q.pop_front();
            while (left == nullptr && !q.empty())
            {
                left = q.front();
                q.pop_front();
            }

            if (q.empty()) throw std::logic_error("?");
            ListNode* right = q.front();
            q.pop_front();
            while (right == nullptr && !q.empty())
            {
                right = q.front();
                q.pop_front();
            }

            q.push_back(mergeTwo(left, right));
        }

        return q.empty() ? nullptr : q.front();
    }
};

/*
mergeTwoLists(left, right):
    if (!left) return right
    if (!right) return left

    head = null
    if left val <= right val
        head = left
        left = left next
    else
        head = right
        right = right next

    while left or right:
        if left && left val <= right val # add left node if lesser
            tail next = left
            left = left next
            tail = tail next
        else if right && if right val < left val # add right node if lesser
            tail next = right
            right = right next
        else if left is null
            tail next = right
        else if right is null
            tail next = left

    return head





*/
