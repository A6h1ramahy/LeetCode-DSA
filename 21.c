/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* result = NULL;
    if(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            result = list1;
            list1 = list1->next;
        }
        else
        {
            result = list2;
            list2 = list2->next;
        }
    }
    else if(list1)
    {
        return list1;
    }
    else
    {
        return list2;
    }

    struct ListNode* cur = result;
    while(list1 && list2)
    {
        if(list1->val < list2->val)
        {
            cur->next = list1;
            list1 = list1->next;
            cur = cur->next;
        }
        else
        {
            cur->next = list2;
            list2 = list2->next;
            cur = cur->next;
        }
    }
    if(list1)
    {
        cur->next = list1;
    }
    else
    {
        cur->next = list2;
    }
    return result;
}
