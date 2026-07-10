/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* prev = NULL;
    while(fast && fast->next)
    {
        prev = slow;
        fast = fast->next->next;
        slow = slow->next;
    }
    if(!prev)
    {
        return true;
    }
    if(fast)
    {
        slow = slow->next;
    }
    prev->next = NULL;
    prev = NULL;
    fast = slow->next;
    while(slow)
    {
        fast = slow->next;
        slow->next = prev;
        prev = slow;
        slow = fast;
    }
    while(prev && head)
    {
        if(prev->val != head->val)
        {
            return false;
        }
        prev = prev->next;
        head = head->next;
    }
    return true;
}
