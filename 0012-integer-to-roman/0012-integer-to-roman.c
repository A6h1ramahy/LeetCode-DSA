char* intToRoman(int num) {
    char *result = malloc(20);
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0, p = 0;

    while (num > 0) {
        while (num >= values[i]) {
            num -= values[i];

            for (int j = 0; symbols[i][j] != '\0'; j++) 
            {
                result[p++] = symbols[i][j];
            }
        }
        i++;
    }

    result[p] = '\0';
    return result;
}