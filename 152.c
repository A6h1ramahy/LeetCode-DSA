int maxProduct(int* nums, int numsSize) {

    int max = nums[0];
    int min = nums[0];
    int result = nums[0];

    for (int i = 1; i < numsSize; i++) {

        if (nums[i] < 0) {
            int temp = max;
            max = min;
            min = temp;
        }

        if (nums[i] > max * nums[i])
            max = nums[i];
        else
            max = max * nums[i];

        if (nums[i] < min * nums[i])
            min = nums[i];
        else
            min = min * nums[i];

        if (max > result)
            result = max;
    }

    return result;
}
