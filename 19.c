/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int count = 0;
    struct ListNode* cur = head;
    while(cur)
    {
        count++;
        cur = cur->next;
    }
    cur = head;
    struct ListNode* prev = NULL;
    for(int i=0; i<(count-n); i++)
    {
        prev = cur;
        cur = cur->next;
    }
    if(!prev && !cur->next)
    {
        free(cur);
        return prev;
    }
    if(!prev && cur->next)
    {
        head = head->next;
        free(cur);
        return head;
    }
    prev->next = cur->next;
    free(cur);
    return head;
}
