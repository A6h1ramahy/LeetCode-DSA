char* multiply(char* num1, char* num2) {
    if (num1[0] == '0' || num2[0] == '0') {
        char* ans = (char*)malloc(2 * sizeof(char));
        ans[0] = '0';
        ans[1] = '\0';
        return ans;
    }

    int m = strlen(num1);
    int n = strlen(num2);

    int* result = (int*)calloc(m + n, sizeof(int));

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';

            int product = digit1 * digit2;

            int current = product + result[i + j + 1];

            result[i + j + 1] = current % 10;
            result[i + j] += current / 10;
        }
    }

    // Skip leading zeros
    int start = 0;

    while (start < m + n && result[start] == 0) {
        start++;
    }

    int length = m + n - start;

    char* answer = (char*)malloc((length + 1) * sizeof(char));

    int index = 0;

    while (start < m + n) {
        answer[index++] = result[start++] + '0';
    }

    answer[index] = '\0';

    free(result);

    return answer;
}
