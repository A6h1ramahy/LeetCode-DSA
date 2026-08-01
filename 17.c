/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char *map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(char *digits, int index, char *curr, char **result, int *returnSize) 
{
    if (digits[index] == '\0') 
    {
        curr[index] = '\0';
        result[*returnSize] = (char *)malloc((strlen(curr) + 1) * sizeof(char));
        strcpy(result[*returnSize], curr);
        (*returnSize)++;
        return;
    }

    char *letters = map[digits[index] - '0'];

    for (int i = 0; letters[i] != '\0'; i++) 
    {
        curr[index] = letters[i];
        backtrack(digits, index + 1, curr, result, returnSize);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    *returnSize = 0;

    if (digits == NULL || digits[0] == '\0')
    {
        return NULL;
    }

    int total = 1;
    for (int i = 0; digits[i] != '\0'; i++) 
    {
        int len = strlen(map[digits[i] - '0']);
        total *= len;
    }

    char **result = (char **)malloc(total * sizeof(char *));
    char *curr = (char *)malloc((strlen(digits) + 1) * sizeof(char));

    backtrack(digits, 0, curr, result, returnSize);

    free(curr);
    return result;
}
