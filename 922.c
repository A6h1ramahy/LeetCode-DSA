/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int i=0, j=1;
    while(i<numsSize && j<numsSize)
    {
        while(i<numsSize && nums[i]%2==0)
        {
            i += 2;
        }
        while(j<numsSize && nums[j]%2!=0)
        {
            j += 2;
        }
        if(i<numsSize && j<numsSize)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i += 2;
            j += 2;
        }
    }

    return nums;
}
