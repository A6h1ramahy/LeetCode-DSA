int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* result = calloc(temperaturesSize, sizeof(int));
    int* stack = malloc(temperaturesSize * sizeof(int));

    int top = -1;

    for(int i = 0; i < temperaturesSize; i++) {
        while(top >= 0 &&
              temperatures[i] > temperatures[stack[top]]) {

            int idx = stack[top--];
            result[idx] = i - idx;
        }

        stack[++top] = i;
    }

    free(stack);

    *returnSize = temperaturesSize;
    return result;
}

