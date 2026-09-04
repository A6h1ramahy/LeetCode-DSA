int firstStableIndex(int* nums, int numsSize, int k) {
    int* min = malloc(numsSize*sizeof(int));
    int m = nums[numsSize-1];
    min[numsSize-1] = m;
    for(int i=numsSize-2; i>=0; i--)
    {
        if(nums[i]<m)
        {
            m = nums[i];
        }
        min[i] = m;
    }
    int max = nums[0];
    if(max-min[0] <= k)
    {
        return 0;
    }
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i]>max)
        {
            max = nums[i];
        }
        if(max-min[i] <= k)
        {
            return i;
        }
    }
    return -1;
}