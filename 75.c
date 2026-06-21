void sortColors(int* nums, int numsSize) {
    int min;
    for(int i=0; i<numsSize-1; i++)
    {
        int min = i;
        for(int j=i+1; j<numsSize; j++)
        {
            if(nums[j]<nums[min])
            {
                min = j;
            }
        }
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}
