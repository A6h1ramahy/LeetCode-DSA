struct Node{
    char str[1001];
    int i;
};

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if(len <= numRows || numRows == 1)
    {
        return s;
    }
    char* result = malloc(len+1);

    struct Node** n = malloc(numRows*sizeof(struct Node*));
    for(int z=0; z<numRows; z++)
    {
        n[z] = malloc(sizeof(struct Node));
        n[z]->i = 0;
    }
    int a=0;
    int j = 0;
    int d = 1;
    while(a<len)
    {
        n[j]->str[(n[j]->i)++] = s[a];
        if(j==0)
        {
            d = 1;
        }
        if(j==numRows-1)
        {
            d = -1;
        }
        j += d;
        a++;
    }
    int y = 0;
    for(int l=0; l<numRows; l++)
    {
        int k = 0;
        while(k < n[l]->i)
        {
            result[y++] = n[l]->str[k++];
        }
    }

    for (int z = 0; z < numRows; z++)
    {
        free(n[z]);
    }
    free(n);
    result[len] = '\0';
    return result;
}
