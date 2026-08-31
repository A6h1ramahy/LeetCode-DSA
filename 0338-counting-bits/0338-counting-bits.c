/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *result = calloc(n+1,sizeof(int));
    *returnSize = 0;
    while((*returnSize)<=n)
    {
        int count = 0;
        int i = (*returnSize);
        while(i!=0)
        {
            if(i%2!=0)
            {
                count++;
            }
            i /= 2;
        }
        result[(*returnSize)++] = count;
    }
    return result;
}