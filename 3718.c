int missingMultiple(int* nums, int numsSize, int k) {
    int num = k;
    int arr[101] = {0};
    for(int i=0; i<numsSize; i++)
    {
        arr[nums[i]] = 1;
    }
    while(num<=100)
    {
        if(!arr[num])
        {
            return num;
        }
        num += k;
    }
    return num;
}
