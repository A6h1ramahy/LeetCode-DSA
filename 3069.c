/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* resultArray(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    
    int* arr1 = malloc(numsSize*sizeof(int));
    int* arr2 = malloc(numsSize*sizeof(int));

    arr1[0] = nums[0];
    arr2[0] = nums[1];

    int p1 = 0;
    int p2 = 0;

    for(int i=2; i<numsSize; i++)
    {
        if(arr1[p1]>arr2[p2])
        {
            arr1[++p1] = nums[i];
        }
        else
        {
            arr2[++p2] = nums[i];
        }
    } 

    for(int j=0; j<=p2; j++)
    {
        arr1[++p1] = arr2[j];
    }

    return arr1;
}
