int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int result = 0;
    int count=0;
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == 0)
        {
            count = 0;
        }
        else
        {
            count++;
            if(result<count)
            {
                result = count;
            }
        }
    }
    return result;
}
