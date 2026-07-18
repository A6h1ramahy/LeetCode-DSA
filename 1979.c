int GCD(int a, int b)
{
    if(b == 0)
        return a;
    return GCD(b, a % b);
}

int findGCD(int* nums, int numsSize) {
    int min = nums[0], max = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        if(nums[i]>max)
        {
            max = nums[i];
        }
        if(nums[i]<min)
        {
            min = nums[i];
        }
    }
    return GCD(min,max);
}

