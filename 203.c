/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    struct ListNode* temp = NULL;
    while(cur!=NULL)
    {
        if(prev!=NULL && cur->val==val)
        {
            prev->next = cur->next;
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        else if(prev==NULL && head->val==val)
        {
            head = cur->next;
            temp = cur;
            cur = cur->next;
            free(temp);
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
