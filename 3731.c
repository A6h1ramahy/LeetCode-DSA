/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;
    return x-y;
}

int* findMissingElements(int* nums, int numsSize, int* returnSize) {
    qsort(nums,numsSize,sizeof(int),compare);
    int max = nums[0];
    int min = nums[0];

    for(int j=1; j<numsSize; j++)
    {
        if(nums[j]>max)
        {
            max = nums[j];
        }
        if(nums[j]<min)
        {
            min = nums[j];
        }
    }

    int* result = malloc((max-min-1)*sizeof(int));
    *returnSize = 0;

    for(int i=0; i<numsSize-1; i++)
    {
        if(nums[i+1] != nums[i]+1)
        {
            result[(*returnSize)++] = nums[i]+1;
            nums[i]++;
            i--;
        }
    }
    return result;
}
