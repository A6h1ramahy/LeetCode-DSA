int findMin(int* nums, int numsSize) {
    int left = 0;
    numsSize--;
    while(left<numsSize)
    {
        int mid = left + (numsSize - left) / 2;
        if(nums[mid]>nums[numsSize])
        {
            left = mid+1;
        }
        else if(nums[mid]<nums[numsSize])
        {
            numsSize = mid;
        }
        else
        {
            numsSize--;
        }
    }
    return nums[left];
}
