/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Merge two sorted lists
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    if (l2) tail->next = l2;

    return dummy.next;
}

// Find middle and split list
struct ListNode* getMid(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* mid = slow->next;
    slow->next = NULL; // split into two halves
    return mid;
}

// Main function
struct ListNode* sortList(struct ListNode* head) {
    // Base case
    if (!head || !head->next)
        return head;

    // Split
    struct ListNode* mid = getMid(head);

    // Recursively sort
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);

    // Merge
    return merge(left, right);
}