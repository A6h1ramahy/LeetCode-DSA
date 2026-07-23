void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int *rows = calloc(matrixSize, sizeof(int));
    int *cols = calloc(matrixColSize[0], sizeof(int));
    for(int i=0; i<matrixSize; i++)
    {
        for(int j=0; j<matrixColSize[0]; j++)
        {
            if(matrix[i][j] == 0)
            {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for(int i=0; i<matrixSize; i++)
    {
        if(rows[i])
        {
            int j=0;
            while(j<matrixColSize[0])
            {
                matrix[i][j++] = 0;
            }
        }
    }
    for(int j=0; j<matrixColSize[0]; j++)
    {
        if(cols[j])
        {
            int i=0;
            while(i<matrixSize)
            {
                matrix[i++][j] = 0;
            }
        }
    }
    free(cols);
    free(rows);
}
