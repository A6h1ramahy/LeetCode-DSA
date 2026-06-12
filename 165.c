int compareVersion(char* version1, char* version2) {
    int len1 = strlen(version1);
    int len2 = strlen(version2);
    int i = 0, j = 0, x = 0, y = 0;
    int v1 = 0, v2 = 0;
    char a[len1], b[len2];
    while(version1[i] != '\0' && version2[j] != '\0')
    {
        while(version1[i] != '.' && version1[i] != '\0')
        {
            a[x++] = version1[i++];
        }
        if(version1[i] == '.')
        {
            i++;
        }

        while(version2[j] != '.' && version2[j] != '\0')
        {
            b[y++] = version2[j++];
        }
        if(version2[j] == '.')
        {
            j++;
        }

        for(int g=0; g<x; g++)
        {
            v1 = v1*10;
            v1 = v1 + (a[g] - '0');
        }
        for(int h=0; h<y; h++)
        {
            v2 = v2*10;
            v2 = v2 + (b[h] - '0');
        }

        if(v1<v2)
        {
            return -1;
        }
        if(v2<v1)
        {
            return 1;
        }

        x = 0;
        y = 0;
        v1 = 0; 
        v2 = 0;
    }

    if(version1[i] == '\0')
    {
        while(version2[j] != '\0')
        {
            if(version2[j]=='.' || version2[j]=='0')
            {
                j++;
            }
            else
            {
                return -1;
            }
        }
    }

    else
    {
        while(version1[i] != '\0')
        {
            if(version1[i]=='.' || version1[i]=='0')
            {
                i++;
            }
            else
            {
                return 1;
            }
        }
    }
    return 0;
}
