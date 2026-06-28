int differenceOfSum(int* nums, int numsSize) {
    int result, esum = 0, dsum = 0, a;
    for(int i=0; i<numsSize; i++)
    {
        esum += nums[i];
        a = nums[i];
        while(a != 0)
        {
            dsum += a%10;
            a = a/10;
        }
    }
    if(esum>dsum)
    {
        result = esum - dsum;
    }
    else
    {
        result = dsum - esum;
    }
    return result;
}
