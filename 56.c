#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b)
{
    int *x = *(int **)a;
    int *y = *(int **)b;

    return x[0]-y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals,intervalsSize,sizeof(int*),compare);
    int **result = malloc(intervalsSize*sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize*sizeof(int));

    int index = 0;
    result[index] = malloc(2*sizeof(int));
    result[index][0] = intervals[0][0];
    result[index][1] = intervals[0][1];
    (*returnColumnSizes)[index] = 2;

    for(int i=1; i<intervalsSize; i++)
    {
        if(intervals[i][0]<=result[index][1])
        {
            if(intervals[i][1]>result[index][1])
            {
                result[index][1] = intervals[i][1];
            }
        }
        else
        {
            index++;
            result[index] = malloc(2*sizeof(int));
            result[index][0] = intervals[i][0];
            result[index][1] = intervals[i][1];
            (*returnColumnSizes)[index] = 2;
        }
    }

    *returnSize = index+1;
    return result;
}