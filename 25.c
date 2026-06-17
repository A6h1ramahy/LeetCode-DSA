/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k==1)
    {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* last;
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;
    struct ListNode* phead = NULL;
    int first = 1;
    while(cur)
    {
        if(cur != head)
        {
            first = 0;
        }
        last = cur;
        prev = NULL;
        for(int i=1; i<k && last; i++)
        {
            last = last->next;
        }
        if(!last)
        {
            break;
        }
        if(phead)
        {
            phead->next = last;
        }
        while(cur != last)
        {
            next = cur->next;
            if(!prev)
            {
                cur->next = last->next;
                phead = cur;
            }
            else
            {
                cur->next = prev;
            }
            prev = cur;
            cur = next;
        }
        if(first)
        {
            head = last;
        }
        cur = last->next;
        last->next = prev;
    }
    return head;
}
