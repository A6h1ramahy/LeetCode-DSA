/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int *table = calloc(numsSize , sizeof(int));
    int* result = malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i=0; i<numsSize; i++)
    {
        table[nums[i]-1]++;
    }
    for(int j=0; j<numsSize; j++)
    {
        if(table[j] == 2)
            result[0] = j+1;

        if(table[j] == 0)
            result[1] = j+1; 
    }
    free(table);
    return result;
}
