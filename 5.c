int isPalindrome(char* s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
        {
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

char* longestPalindrome(char* s) {

    int len = strlen(s);

    int maxLen = 1;
    int start = 0;

    for(int i = 0; i < len; i++)
    {
        for(int j = i; j < len; j++)
        {
            if(isPalindrome(s, i, j))
            {
                if(j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
    }

    char *result = (char*)malloc(maxLen + 1);

    for(int i = 0; i < maxLen; i++)
    {
        result[i] = s[start + i];
    }

    result[maxLen] = '\0';

    return result;
}
