/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur1 = headA; 
    struct ListNode *cur2 = headB;
    while(cur1!=NULL)
    {
        cur2 = headB;
        while(cur2!=NULL)
        {
            if(cur1==cur2)
            {
                return cur1;
            }
            cur2 = cur2->next;
        }
        cur1=cur1->next;
    }
    return NULL;
}