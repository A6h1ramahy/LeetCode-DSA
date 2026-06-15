/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int depth,
         int* result, int* returnSize) {

    if (root == NULL)
        return;

    if (depth == *returnSize)
        result[(*returnSize)++] = root->val;

    dfs(root->right, depth + 1, result, returnSize);
    dfs(root->left, depth + 1, result, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* result = malloc(100 * sizeof(int));

    dfs(root, 0, result, returnSize);

    return result;
}
