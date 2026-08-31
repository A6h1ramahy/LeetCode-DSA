struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *cur1 = headA;
    struct ListNode *cur2 = headB;

    while (cur1 != cur2) 
    {
        if (cur1 == NULL)
        {
            cur1 = headB;
        }
        else
        {
            cur1 = cur1->next;
        }

        if (cur2 == NULL)
        {
            cur2 = headA;
        }
        else
        {
            cur2 = cur2->next;
        }
    }

    return cur1;
}