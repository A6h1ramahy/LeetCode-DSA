/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** insert(int** intervals, int intervalsSize, int* intervalsColSize,
             int* newInterval, int newIntervalSize,
             int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    *returnColumnSizes = calloc(intervalsSize + 1, sizeof(int));
    int **result = malloc((intervalsSize + 1) * sizeof(int*));
    int i = 0, done = 0;

    for(i = 0; i < intervalsSize && !done; i++)
    {
        if(intervals[i][1] < newInterval[0])
        {
            result[*returnSize] = malloc(2 * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;
            result[*returnSize][0] = intervals[i][0];
            result[*returnSize][1] = intervals[i][1];
            (*returnSize)++;
        }

        else if(intervals[i][0] > newInterval[1])
        {
            result[*returnSize] = malloc(2 * sizeof(int));
            (*returnColumnSizes)[*returnSize] = 2;
            result[*returnSize][0] = newInterval[0];
            result[*returnSize][1] = newInterval[1];
            (*returnSize)++;
            done = 1;
            i--;
        }

        else
        {
            if(intervals[i][0] < newInterval[0])
                newInterval[0] = intervals[i][0];
            if(intervals[i][1] > newInterval[1])
                newInterval[1] = intervals[i][1];
        }
    }

    if(!done)
    {
        result[*returnSize] = malloc(2 * sizeof(int));
        (*returnColumnSizes)[*returnSize] = 2;
        result[*returnSize][0] = newInterval[0];
        result[*returnSize][1] = newInterval[1];
        (*returnSize)++;
    }

    while(i < intervalsSize)
    {
        result[*returnSize] = malloc(2 * sizeof(int));
        (*returnColumnSizes)[*returnSize] = 2;
        result[*returnSize][0] = intervals[i][0];
        result[*returnSize][1] = intervals[i][1];
        (*returnSize)++;
        i++;
    }

    return result;
}
