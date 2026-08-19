/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtrack(int* nums, int numsSize, int* path, int pathSize, int** result, int* returnSize, int* used)
{
    if(pathSize == numsSize)
    {
        result[*returnSize] = malloc(numsSize * sizeof(int));

        for(int i = 0; i < numsSize; i++)
        {
            result[*returnSize][i] = path[i];
        }

        (*returnSize)++;
        return;
    }

    for(int i = 0; i < numsSize; i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            path[pathSize] = nums[i];

            backtrack(nums, numsSize, path, pathSize + 1, result, returnSize, used);

            used[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int total = 1;

    for(int i = 2; i <= numsSize; i++)
    {
        total *= i;
    }

    int** result = malloc(total * sizeof(int*));
    int* path = malloc(numsSize * sizeof(int));
    int* used = calloc(numsSize, sizeof(int));
    
    *returnSize = 0;

    *returnColumnSizes = malloc(total * sizeof(int));

    backtrack(nums, numsSize, path, 0, result, returnSize, used);

    for(int i = 0; i < *returnSize; i++)
    {
        (*returnColumnSizes)[i] = numsSize;
    }
    free(path);
    free(used);
    return result;
}
