/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(numRows*sizeof(int*));
    *returnColumnSizes = malloc(numRows*sizeof(int));
    *returnSize = 0;
    for(int i=0; i<numRows; i++)
    {
        result[*returnSize] = malloc((i+1)*sizeof(int));
        result[*returnSize][0] = 1;
        result[*returnSize][i] = 1;
        for(int k=1; k<i; k++)
        {
            result[*returnSize][k] = result[(*returnSize)-1][k-1] + result[(*returnSize)-1][k];
        }
        (*returnColumnSizes)[*returnSize] = i+1;
        (*returnSize)++;
    }

    return result;
}
