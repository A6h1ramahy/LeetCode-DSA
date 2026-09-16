int cmp(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int c = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < numsSize-2; i++) 
    {
        int l = i + 1;
        int r = numsSize - 1;

        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if (sum == target) 
            {
                return sum;
            }

            if (abs(sum - target) < abs(c - target)) 
            {
                c = sum;
            }

            if (sum < target) 
            {
                l++;
            } 
            else 
            {
                r--;
            }
        }
    }

    return c;
}