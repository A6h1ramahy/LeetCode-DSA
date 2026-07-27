int maxProduct(int* nums, int numsSize) {
    int a = nums[0];
    int b;
    if(nums[1]<a)
    {
        b = nums[1];
    }
    else
    {
        b = a;
        a = nums[1];
    }
    for(int i=2; i<numsSize; i++)
    {
        if(nums[i]>a)
        {
            b = a;
            a = nums[i];
        }
        else if(nums[i]>b)
        {
            b = nums[i];
        }
    }
    return (a-1)*(b-1);
}
