int cmp(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);  
}

long long maxSum(int* nums, int numsSize, int k, int mul)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int r = (mul > 1) ? (mul - 1) : 0;
    if (r > k)
        r = k;

    long long ans = 0;

    for (int i = 0; i < r; i++)
    {
        ans += 1LL * nums[i] * (mul - i);
    }

    for (int i = r; i < k; i++)
    {
        ans += nums[i];
    }

    return ans;
}
