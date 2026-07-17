int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int majorityElement(int* nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), compare);

    if (numsSize == 1)
        return nums[0];

    int count = 1;

    for (int i = 1; i < numsSize; i++)
    {
        if (nums[i] == nums[i - 1])
            count++;
        else
            count = 1;

        if (count > numsSize / 2)
            return nums[i];
    }

    return -1;   
}
