char findTheDifference(char* s, char* t) {
    int nums[26] = {0};
    int i=0;
    while(s[i]!='\0')
    {
        nums[s[i]-'a']++;
        i++;
    }
    i=0;
    while(t[i]!='\0')
    {
        nums[t[i]-'a']--;
        i++;
    }
    for(i=0; i<26; i++)
    {
        if(nums[i]==-1)
        {
            break;
        }
    }
    return (char)(i+'a');
}