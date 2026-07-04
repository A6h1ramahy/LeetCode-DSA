int removeDuplicates(int* nums, int numsSize) {
    int i=0, ptr = 1, dup;

    if(numsSize==0)
    {
        return 0;
    }

    while(i<numsSize-1)
    {
        if(nums[i] == nums[i+1])
        {
            i++;
        }
        else
        {
            nums[ptr++] = nums[++i];
        }
    }
    return ptr;
}
