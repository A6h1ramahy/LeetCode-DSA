bool isPalindrome(char* s) {
    int capacity = strlen(s);
    char* str = malloc(capacity+1);
    int len = 0;
    for(int i = 0; i<capacity; i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
        {
            str[len++] = s[i];
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            str[len++] = s[i] + 32;
        }
    }
    str[len] = '\0';
    int left = 0;
    int right = len-1;
    while(left<right)
    {
        if(str[left++] != str[right--])
        {
            free(str);
            return false;
        }
    }
    free(str);
    return true;
}
