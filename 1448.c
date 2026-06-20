/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int result(struct TreeNode* node, int value)
{
    if(!node)
    {
        return 0;
    }
    if(node->val >= value)
    {
        return 1+result(node->left,node->val)+result(node->right,node->val);
    }
    return result(node->left,value)+result(node->right,value);
}

int goodNodes(struct TreeNode* root){
    return result(root, root->val);
}
