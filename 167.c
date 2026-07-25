/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int low = 0;
    int high = numbersSize-1;
    int *result = malloc(2*sizeof(int));
    while(low<high)
    {
        if(numbers[low]+numbers[high] == target)
        {
            result[0] = low+1;
            result[1] = high+1;
            *returnSize = 2;
            return result;
        }
        if(numbers[low]+numbers[high] < target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return NULL;
}
