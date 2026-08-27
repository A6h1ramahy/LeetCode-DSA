/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if(postorderSize==0 || inorderSize==0)
    {
        return NULL;
    }
    struct TreeNode* root = malloc(sizeof(struct TreeNode));
    root->val = postorder[postorderSize-1];
    root->left = NULL;
    root->right = NULL;

    int left = 0;
    while(inorder[left] != root->val)
    {
        left++;
    }

    root->right = buildTree(inorder+left+1, inorderSize-left-1, postorder+left, postorderSize-left-1);

    root->left = buildTree(inorder, left, postorder, left);

    return root;
}