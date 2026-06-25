char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = malloc(len+1);
    int ptr=0;
    for(int i=len-1; i>=0; i--)
    {
        if((i<len-1 && (s[i] == ' ' && s[i+1] != ' ')) || (i == 0 && s[i] != ' '))
        {
            int j;
            if (s[i] == ' ')
                j = i + 1;
            else
                j = i;
            while(j<len && s[j] != ' ')
            {
                result[ptr++] = s[j++];
            }
            result[ptr++] = ' ';
        }
    }
    result[--ptr] = '\0';
    return result;
}
