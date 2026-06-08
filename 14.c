char* longestCommonPrefix(char** strs, int strsSize) {
    char str;
    char *result = malloc(201);
    int ptr = 0;
    int loop = 1;
    while(loop==1)
    {
        str = strs[0][ptr];
        if(str=='\0')
        {
            break;
        }
        for(int i=1; i<strsSize; i++)
        {
            if(strs[i][ptr] != str)
            {
                loop = 0;
                break;
            }
        }
        if(loop == 1)
        {
            result[ptr++] = str;
        }
    }
    result[ptr] = '\0';
    return result;
}
