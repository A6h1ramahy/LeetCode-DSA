/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = 0;
    int* result = malloc(matrixSize*matrixColSize[0]*sizeof(int));
    int top = 0;
    int left = 0;
    int bottom = matrixSize-1;
    int right = matrixColSize[0]-1;
    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; i++)
        {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        if(top <= bottom && left <= right)
        {
            for(int j=top; j<=bottom; j++)
            {
                result[(*returnSize)++] = matrix[j][right];
            }
            right--;
        }
        if(top <= bottom && left <= right)
        {
            for(int k=right; k>=left; k--)
            {
                result[(*returnSize)++] = matrix[bottom][k];
            }
            bottom--;
        }

        if(top <= bottom && left <= right)
        {
            for(int l=bottom; l>=top; l--)
            {
                result[(*returnSize)++] = matrix[l][left];
            }
            left++;
        }
    }

    return result;
}
