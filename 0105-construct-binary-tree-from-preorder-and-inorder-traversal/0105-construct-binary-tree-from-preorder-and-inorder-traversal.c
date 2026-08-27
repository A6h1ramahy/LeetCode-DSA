/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    if(preorderSize==0 || inorderSize==0)
    {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;

    int left = 0;
    while(inorder[left] != root->val)
    {
        left++;
    }

    root->left = buildTree(preorder+1, left, inorder, left);

    root->right = buildTree(preorder+left+1, preorderSize-left-1, inorder+left+1, preorderSize-left-1);

    return root;
}