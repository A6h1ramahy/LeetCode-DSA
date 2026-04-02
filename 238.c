/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *ans = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int prod = 1;
    int zero = 0;

    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == 0)
        {
            zero++;
            continue;
        }
        prod = prod*nums[i];
    }

    if(zero == 0)
    {
        for(int j=0; j<numsSize; j++)
        {
            ans[j] = prod/nums[j];
        }
    }
    else if(zero==1)
    {
        for(int k=0; k<numsSize; k++)
        {
            if(nums[k]!=0)
            {
                ans[k] = 0;
            }
            else
            {
                ans[k] = prod;
            }
        }
    }
    else
    {
        for(int l=0; l<numsSize; l++)
        {
            ans[l] = 0;
        }
    }
    return ans;
}