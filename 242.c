bool isAnagram(char* s, char* t) {
    int len1 = strlen(s);
    int len2 = strlen(t);

    if(len1 != len2)
    {
        return false;
    }

    int count[26] = {0};
    for(int i=0; i<len1; i++)
    {
        count[s[i]-'a']++;
    }
    for(int j=0; j<len2; j++)
    {
        count[t[j]-'a']--;
    }
    for(int k=0; k<26; k++)
    {
        if(count[k] != 0)
        {
            return false;
        }
    }
    return true;
}
