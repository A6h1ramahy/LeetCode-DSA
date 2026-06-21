/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int compare(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x > y)
        return 1;
    if (x < y)
        return -1;
    return 0;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
    int *result = calloc(k, sizeof(int));
    int *count = calloc(k, sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    *returnSize = 0;

    for (int i = 0; i < numsSize; i++)
    {
        int c = 1;

        while (i < numsSize - 1 && nums[i] == nums[i + 1])
        {
            c++;
            i++;
        }

        int pos = *returnSize;

        for (int j = 0; j < *returnSize; j++)
        {
            if (c > count[j])
            {
                pos = j;
                break;
            }
        }

        if (*returnSize < k)
        {
            (*returnSize)++;
        }
        else if (pos == k)
        {
            continue;
        }

        for (int j = *returnSize - 1; j > pos; j--)
        {
            count[j] = count[j - 1];
            result[j] = result[j - 1];
        }

        if (pos < k)
        {
            count[pos] = c;
            result[pos] = nums[i];
        }
    }

    return result;
}

