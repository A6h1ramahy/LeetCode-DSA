/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** shiftGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes) {
    *returnSize = gridSize;
    *returnColumnSizes = malloc(gridSize*sizeof(int));
    int **result = malloc(gridSize*sizeof(int *));

    for(int z=0; z<gridSize; z++)
    {
        result[z] = malloc(gridColSize[0]*sizeof(int));
        (*returnColumnSizes)[z] = gridColSize[0];
    }

    for(int i=0; i<gridSize; i++)
    {
        for(int j=0; j<gridColSize[0]; j++)
        {
            int old = i*gridColSize[0] + j;
            int new = (old+k)%(gridSize*gridColSize[0]);

            int row = new/gridColSize[0];
            int col = new%gridColSize[0];

            result[row][col] = grid[i][j];
        }
    }
    return result;
}
