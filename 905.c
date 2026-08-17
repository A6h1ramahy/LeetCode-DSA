/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int left=0, right=numsSize-1;
    *returnSize = numsSize;
    while(left<right)
    {
        while(left<numsSize && nums[left]%2==0)
        {
            left++;
        }
        while(right>=0 && nums[right]%2!=0)
        {
            right--;
        }
        if(left<right)
        {
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
        }
        left++;
        right--;
    }
    return nums;
}
