int calculate(char* s) {
    int n = strlen(s);
    int result = 0;
    int current = 0;
    int num = 0;
    char op = '+';

    for (int i = 0; i <= n; i++) {

        if (i < n && s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        }

        if (i == n || (s[i] != ' ' &&
                       !(s[i] >= '0' && s[i] <= '9'))) {

            if (op == '+') {
                result += current;
                current = num;
            }
            else if (op == '-') {
                result += current;
                current = -num;
            }
            else if (op == '*') {
                current *= num;
            }
            else if (op == '/') {
                current /= num;
            }

            op = s[i];
            num = 0;
        }
    }

    return result + current;
}