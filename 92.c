/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    left--;
    right--;
    if (right - left == 0) {
        return head;
    }
    
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    int i;
    for (i = 0; i < left; i++) {
        prev = cur;
        cur = cur->next;
    }

    i = 0;
    struct ListNode* n;
    struct ListNode* first = cur;
    struct ListNode* p = prev;

    while (i < (right - left) + 1) {
        n = cur->next;
        cur->next = prev;
        prev = cur;
        cur = n;
        i++;
    }

    first->next = cur;

    if (p) {
        p->next = prev;
    } 

    else {
        return prev;
    }
    return head;
}
