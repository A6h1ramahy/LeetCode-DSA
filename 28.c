int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    for(int i=0; i<=len1-len2; i++)
    {
        for(int k=i,j=0; j<len2; j++,k++)
        {
            if(haystack[k] != needle[j])
            {
                break;
            }
            else if(j == len2-1)
            {
                return i;
            }
        }
    }
    return -1;
}
