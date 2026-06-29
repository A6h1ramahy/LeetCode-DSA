char* countAndSay(int n) {
    char *curr = (char *)malloc(5000);
    strcpy(curr, "1");

    for (int k = 2; k <= n; k++) {
        char *next = (char *)malloc(5000);
        int idx = 0;

        for (int i = 0; curr[i] != '\0'; ) {
            int count = 1;

            while (curr[i] == curr[i + 1]) {
                count++;
                i++;
            }

            idx += sprintf(next + idx, "%d%c", count, curr[i]);
            i++;
        }

        free(curr);
        curr = next;
    }

    return curr;
}

