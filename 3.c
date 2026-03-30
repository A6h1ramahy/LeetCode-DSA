int lengthOfLongestSubstring(char* s) {
    int seen[256] = {0};
    int start = 0;
    int max = 0;
    int total;
    for(int end=0; s[end]!='\0'; end++)
    {
        while(seen[s[end]] != 0)
        {
            seen[s[start++]] = 0;
        }
        seen[s[end]] = 1;
        total = end-start+1;
        if(total>max)
        {
            max = total;
        }
    }
    return max;
}