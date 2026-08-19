/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {\
    int *result = malloc(2*numsSize*sizeof(int));
    *returnSize = 0;
    for(int i=0; i<numsSize; i++)
    {
        result[(*returnSize)++] = nums[i];
    }
    for(int i=0; i<numsSize; i++)
    {
        result[(*returnSize)++] = nums[i];
    }
    return result;
}
