int* constructTransformedArray(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(numsSize * sizeof(int));
    *returnSize = numsSize;

    for (int i = 0; i < numsSize; i++) {
        int idx = ((i + nums[i]) % numsSize + numsSize) % numsSize;
        ans[i] = nums[idx];
    }

    return ans;
}
