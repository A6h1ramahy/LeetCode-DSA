int minimumDeletions(int* nums, int numsSize) {
    if(numsSize<=2)
    {
        return numsSize;
    }
    int min = 0;
    int max = 0;
    int d;
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i]<nums[min])
        {
            min = i;
        }
        if(nums[i]>nums[max])
        {
            max = i;
        }
    }
    if(min>max)
    {
        d = min;
        min = max;
        max = d;
    }

    d = max + 1;
    if(numsSize-min < d)
    {
        d = numsSize - min;
    }
    if((min+1)+(numsSize-max) < d)
    {
        d = (min+1)+(numsSize-max);
    }
    return d;
}