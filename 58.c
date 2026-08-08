int lengthOfLastWord(char* s) {
    int result = 0;
    int i = strlen(s)-1;
    while(i >= 0 && s[i] == ' ')
    {
        i--;
    }
    while(i >= 0 && s[i] != ' ')
    {
        result++;
        i--;
    }
    return result;
}
