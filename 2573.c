char* findTheString(int** lcp, int n, int* lcpColSize) {
    char* s = (char*)malloc((n + 1) * sizeof(char));
    for (int i = 0; i < n; i++) s[i] = '?';
    s[n] = '\0';

    char curr = 'a';

    // Step 1: Assign characters
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') continue;

        if (curr > 'z') return "";

        s[i] = curr;

        for (int j = i + 1; j < n; j++) {
            if (lcp[i][j] > 0) {
                s[j] = curr;
            }
        }

        curr++;
    }

    // Step 2: Validate LCP matrix
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        dp[i] = (int*)calloc((n + 1), sizeof(int));
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            } else {
                dp[i][j] = 0;
            }

            if (dp[i][j] != lcp[i][j]) {
                return "";
            }
        }
    }
    return s;
}