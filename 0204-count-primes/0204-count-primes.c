int countPrimes(int n) {
    if (n <= 2)
        return 0;

    bool *arr = malloc(n * sizeof(bool));
    memset(arr, true, n * sizeof(bool));

    arr[0] = arr[1] = false;

    for (int i = 4; i < n; i += 2)
        arr[i] = false;

    for (int i = 3; i * i < n; i += 2) {
        if (arr[i]) {
            for (int j = i * i; j < n; j += 2 * i)
                arr[j] = false;
        }
    }

    int count = 1;

    for (int i = 3; i < n; i += 2) {
        if (arr[i])
            count++;
    }

    free(arr);

    return count;
}