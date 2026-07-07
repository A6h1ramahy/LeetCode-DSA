void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    for(int i=0; i<matrixSize; i++)
    {
        for(int j=i+1; j<matrixSize; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for(int k=0; k<matrixSize; k++)
    {
        int left = 0, right = matrixSize-1;
        while(left < right)
        {
            int t = matrix[k][left];
            matrix[k][left++] = matrix[k][right];
            matrix[k][right--] = t;
        }
    }
}
