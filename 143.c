/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverse(struct ListNode* head)
{
    if(!head)
    {
        return NULL;
    }
    struct ListNode* c = head;
    struct ListNode* n = NULL;
    struct ListNode* prev = NULL;
    while(c->next != NULL)
    {
        n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }
    c->next = prev;
    return c;
}

void reorderList(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* head1 = NULL;
    while(fast!=NULL && fast->next !=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    head1 = slow->next;
    slow->next = NULL;
    head1 = reverse(head1);
    struct ListNode* cur = head;
    struct ListNode* nxt = NULL;
    struct ListNode* nxt1 = NULL;
    while(cur!=NULL && head1!=NULL)
    {
        nxt = cur->next;
        nxt1 = head1->next;
        cur->next = head1;
        head1->next = nxt;
        head1 = nxt1;
        cur = nxt;
    }
}
