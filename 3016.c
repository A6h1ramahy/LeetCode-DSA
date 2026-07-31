int max(int *count)
{
    int m = 0;
    for(int j=1; j<26; j++)
    {
        if(count[j]>count[m])
        {
            m = j;
        }
    }
    return m;
}

int minimumPushes(char* word) {
    int *count = calloc(26,sizeof(int));
    int result = 0;
    int c = 0;
    int index;

    for(int i=0; word[i]!='\0'; i++)
    {
        if(!count[word[i]-'a'])
        {
            c++;
        }
        count[word[i]-'a']++;
    }

    for(int k=0; k<c; k++)
    {
        index = max(count);
        result += ((k/8)+1)*count[index];
        count[index] = 0;
    }

    free(count);
    return result;
}
