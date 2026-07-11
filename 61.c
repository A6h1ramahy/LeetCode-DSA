/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(!head || !head->next || k==0)
    {
        return head;
    }

    struct ListNode* cur = head;
    int count = 0;
    while(cur)
    {
        count++;
        cur = cur->next;
    }

    cur = head;
    struct ListNode* prev = NULL;
    k = k%count;

    if(k == 0)
    {
        return head;
    }

    for(int i=0; i<count-k; i++)
    {
        prev = cur;
        cur = cur->next;
    }

    prev->next = NULL;
    prev = head;
    head = cur;

    while(cur->next)
    {
        cur = cur->next;
    }
    cur->next = prev;
    
    return head;
}
