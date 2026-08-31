/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    int *result = calloc(n + 1, sizeof(int));
    *returnSize = n + 1;

    for(int i = 1; i <= n; i++)
    {
        result[i] = result[i >> 1] + (i & 1);
    }

    return result;
}