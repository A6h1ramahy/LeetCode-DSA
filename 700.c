/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    struct TreeNode* cur = root;
    while(cur)
    {
        if(cur->val == val)
        {
            break;
        }
        else if(cur->val < val)
        {
            cur = cur->right;
        }
        else
        {
            cur = cur->left;
        }
    }
    return cur;
}
