int repeatedStringMatch(char* a, char* b) {
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = lenB + 2 * lenA;
    char *temp = malloc(maxLen + 1);
    temp[0] = '\0';
    int count = 0;

    while (strlen(temp) < lenB) {
        strcat(temp, a);
        count++;
    }

    if (strstr(temp, b) != NULL) {
        free(temp);
        return count;
    }

    strcat(temp, a);
    count++;

    if (strstr(temp, b) != NULL) {
        free(temp);
        return count;
    }

    free(temp);
    return -1;
}
