bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int m = matrixSize;
    int n = matrixColSize[0];

    int left = 0;
    int right = (m * n) - 1;

    while(left<=right)
    {
        int mid = left + (right-left)/2;
        m = mid / matrixColSize[0];
        n = mid % matrixColSize[0];

        if(matrix[m][n] == target)
        {
            return true;
        }

        if(matrix[m][n] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return false;
}
