/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b)
{
    int *row1 = *(int **)a;
    int *row2 = *(int **)b;

    int d1 = (row1[0]*row1[0]) + (row1[1]*row1[1]);
    int d2 = (row2[0]*row2[0]) + (row2[1]*row2[1]);

    return d1-d2;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes) {
    int **result = malloc(k*sizeof(int*));
    *returnSize = k;
    *returnColumnSizes = malloc(k*sizeof(int));

    qsort(points,pointsSize,sizeof(points[0]),compare);

    for(int j=0; j<k; j++)
    {
        (*returnColumnSizes)[j] = 2;
        result[j] = malloc(sizeof(int)*2);
        result[j][0] = points[j][0];
        result[j][1] = points[j][1];
    }

    return result;
}

