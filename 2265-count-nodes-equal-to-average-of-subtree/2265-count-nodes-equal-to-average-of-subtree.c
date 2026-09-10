/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
int dfs(struct TreeNode* root, int* nodes) 
{
    if (!root) 
    {
        *nodes = 0;
        return 0;
    }

    int leftNodes, rightNodes;
    int leftSum = dfs(root->left, &leftNodes);
    int rightSum = dfs(root->right, &rightNodes);
    int sum = leftSum + rightSum + root->val;
    *nodes = leftNodes + rightNodes + 1;

    if (root->val == sum / (*nodes)) 
    {
        count++;
    }

    return sum;
}

int averageOfSubtree(struct TreeNode* root) {
    count = 0;
    int nodes;
    dfs(root, &nodes);
    return count;
}