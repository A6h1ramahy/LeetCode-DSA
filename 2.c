/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* ans;
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* l4;
    ans = l3;
    l3->val = -1;
    l3->next = NULL;
    int a;
    int carry = 0;
    while(l1 && l2)
    {
        a = l1->val + l2->val + carry;
        if(a>=10)
        {
            carry = a/10;
            a = a%10;
        }
        else
        {
            carry = 0;
        }
        l3->val = a;
        l4 = l3;
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->next = NULL;
        l1 = l1->next;
        l2 = l2->next;
    }
    
    while(!l1 && l2)
    {
        a = l2->val+carry;
        if(a>=10)
        {
            carry = a/10;
            a = a%10;
        }
        else
        {
            carry = 0;
        }
        l3->val = a;
        l4 = l3;
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->next = NULL;
        l2 = l2->next;
    }

    while(!l2 && l1)
    {
        a = l1->val+carry;
        if(a>=10)
        {
            carry = a/10;
            a = a%10;
        }
        else
        {
            carry = 0;
        }
        l3->val = a;
        l4 = l3;
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->next = NULL;
        l1 = l1->next;
    }

    if (carry == 0)
    {   
        l4->next = NULL;
        free(l3);
    }
    else
    {
        l3->val = carry;
    }
    return ans;
}