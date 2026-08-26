/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    *returnSize = numsSize;
    int* result = malloc(numsSize*sizeof(int));
    int i = 0;
    for(int j=0; j<n; j++)
    {
        result[i++] = nums[j];
        result[i++] = nums[j+n];
    }
    return result;
}
