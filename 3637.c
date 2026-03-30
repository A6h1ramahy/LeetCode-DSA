bool isTrionic(int* nums, int numsSize) {
    int p=0;
    int q=0;
    int r=0;
    for(int i=0; i<numsSize-1; i++)
    {
        if(nums[i]<nums[i+1])
        {
            p++;
        }
        else
        {
            break;
        }
    }
    if(p!=0)
    {
        for(int j=p; j<numsSize-1; j++)
        {
            if(nums[j]>nums[j+1])
            {
                q=j+1;
            }
            else
            {
                break;
            }
        }
    }
    if(q!=0)
    {
        for(int k=q; k<numsSize-1; k++)
        {
            if(nums[k]<nums[k+1])
            {
                r=k+1;
            }
            else
            {
                break;
            }
        }
    }
    if(r==numsSize-1)
    {
        return true;
    }
    return false;
}