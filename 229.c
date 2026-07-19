/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int compare(const void* a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
    if(x==y)
    {
        return 0;
    }
    if(x>y)
    {
        return 1;
    }
    return -1;
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),compare);
    int count=1;
    int *result = malloc(numsSize*sizeof(int));
    *returnSize = 0;
    for(int i=0; i<numsSize; i++)
    {
        if((i+1<numsSize) && nums[i]==nums[i+1])
        {
            count++;
        }
        else
        {
            if(count>(numsSize/3))
            {
                result[(*returnSize)++] = nums[i];
            }
            count = 1;
        }
    }
    return result;
}

