/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int* result = malloc((rowIndex+1)*sizeof(int));
    result[0] = 1;

    for(int i=1; i<=rowIndex; i++)
    {
        for(int j=i; j>=1; j--)
        {
            if(i==j)
            {
                result[j] = 1;
            }
            else
            {
                result[j] = result[j] + result[j-1];
            }
        }
    }

    return result;
}