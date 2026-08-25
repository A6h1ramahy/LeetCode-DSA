/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    struct ListNode* cur = head;
    struct ListNode* sec = head->next;
    struct ListNode* prev = NULL;
    while (cur && sec) {
        if (prev) {
            prev->next = sec;
            cur->next = sec->next;
            sec->next = cur;
        } else {
            head = sec;
            cur->next = sec->next;
            sec->next = cur;
        }
        prev = cur;
        cur = cur->next;
        if (cur) {
            sec = cur->next;
        }
    }
    return head;
}
