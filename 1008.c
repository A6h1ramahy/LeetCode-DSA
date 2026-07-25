/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(int* preorder, int preorderSize, int *index, int bound)
{
    if(*index >= preorderSize || preorder[*index]>bound)
    {
        return NULL;
    }
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = preorder[(*index)++];
    node->left = build(preorder, preorderSize, index, node->val);
    node->right = build(preorder, preorderSize, index, bound);

    return node;
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize) 
{
    int index = 0;
    return build(preorder, preorderSize, &index, INT_MAX);
}
