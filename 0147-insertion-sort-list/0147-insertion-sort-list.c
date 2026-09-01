/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL)
    {
        return head;
    }

    struct ListNode* cur = head->next;
    struct ListNode* prev = head;
    while(cur != NULL)
    {
        if(cur->val >= prev->val)
        {
            prev = prev->next;
            cur = cur->next;
        }
        else if(cur->val <= head->val)
        {
            prev->next = cur->next;
            cur->next = head;
            head = cur;
            cur = prev->next;
        }
        else
        {
            struct ListNode* c = head->next;
            struct ListNode* p = head;
            prev->next = cur->next;
            while(1)
            {
                if(cur->val <= c->val)
                {
                    p->next = cur;
                    cur->next = c;
                    break;
                }
                p = p->next;
                c = c->next;
            }
            cur = prev->next;
        }
    }
    return head;
}