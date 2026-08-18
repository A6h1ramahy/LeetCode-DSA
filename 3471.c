int largestInteger(int* nums, int numsSize, int k) {
    int freq[51] = {0};
    for(int i=0; i<numsSize; i++)
    {
        freq[nums[i]]++;
    }
    int ans;
    if(k==numsSize)
    {
        ans = nums[0];
        for(int i=1; i<numsSize; i++)
        {
            if(nums[i]>ans)
            {
                ans = nums[i];
            }
        }
        return ans;
    }
    if(k==1)
    {
        ans = -1;
        for(int i=0; i<numsSize; i++)
        {
            if(nums[i]>ans && freq[nums[i]]==1)
            {
                ans = nums[i];
            }
        }
        return ans;
    }
    int max = nums[0];
    int smax = nums[numsSize-1];
    if(max<smax)
    {
        ans = max;
        max = smax;
        smax = ans;
    }
    if(freq[max]==1)
    {
        return max;
    }
    else if(freq[smax]==1)
    {
        return smax;
    }
    return -1;
}
