/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int more = 1;
    int *result;
    for(int i=0; i<digitsSize; i++)
    {
        if(digits[i] != 9)
        {
            more = 0;
            break;
        }
    }
    if(more)
    {
        result = malloc((digitsSize+1)*sizeof(int));
        result[0] = 1;
        for(int j=1; j<=digitsSize; j++)
        {
            result[j] = 0;
        }
        *returnSize = digitsSize+1;
    }
    else
    {
        result = malloc(digitsSize*sizeof(int));
        int k = digitsSize-1, add=0;
        while(k>=0)
        {
            if(add)
            {
                result[k] = digits[k];
            }
            else if((digits[k] < 9) && !add)
            {
                result[k] = digits[k] + 1;
                add = 1;
            }
            else if((digits[k] == 9) && !add)
            {
                result[k] = 0;
            }
            k--;
        }
        *returnSize = digitsSize;
    }
    return result;
}
