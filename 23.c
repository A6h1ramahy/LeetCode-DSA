/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    struct ListNode* head = NULL;
    int i,j,ptr;
    for(i=0; i<listsSize; i++)
    {
        if(lists[i])
        {
            head = lists[i];
            break;
        }
    }
    if(!head)
    {
        return head;
    }
    ptr = i;
    for(j=0; j<listsSize; j++)
    {
        if(lists[j] && (lists[j]->val < head->val))
        {
            head = lists[j];
            ptr = j;
        }
    }
    lists[ptr] = lists[ptr]->next;
    struct ListNode* node = head;
    
    while(1)
    {
        struct ListNode* min = NULL;
        for(i=0; i<listsSize; i++)
        {
            if(lists[i])
            {
                min = lists[i];
                break;
            }
        }
        if(!min)
        {
            return head;
        }
        ptr = i;
        for(j=0; j<listsSize; j++)
        {
            if(lists[j] && (lists[j]->val < min->val))
            {
                min = lists[j];
                ptr = j;
            }
        }
        lists[ptr] = lists[ptr]->next;
        node->next = min;
        node = node->next;        
    }
}
