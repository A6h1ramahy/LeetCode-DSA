struct TreeNode* build(int *nums, int l, int r)
{
    if(l > r)
        return NULL;

    int mid = l + (r - l) / 2;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = nums[mid];

    root->left = build(nums, l, mid - 1);
    root->right = build(nums, mid + 1, r);

    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    return build(nums, 0, numsSize - 1);
}
