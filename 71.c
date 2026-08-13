char* simplifyPath(char* path) {
    int len = strlen(path);

    char* result = malloc(len + 1);

    int i = 0;  
    int j = 0;  

    result[i++] = '/';

    while (j < len) 
    {
        while (j < len && path[j] == '/')
        {
            j++;
        }

        if (j >= len)
        {
            break;
        }

        int start = j;

        while (j < len && path[j] != '/')
        {
            j++;
        }

        int size = j - start;

        if (size == 1 && path[start] == '.') 
        {
            continue;
        }

        if (size == 2 && path[start] == '.' && path[start + 1] == '.') 
        {
            if (i > 1) 
            {
                i--;

                while (i > 0 && result[i - 1] != '/')
                {
                    i--;
                }
                if (i > 1)
                {
                    i--;
                }
            }

            continue;
        }

        if (i > 1)
        {
            result[i++] = '/';
        }

        for (int k = start; k < start + size; k++)
        {
            result[i++] = path[k];
        }
    }

    if (i > 1 && result[i - 1] == '/')
    {
        i--;
    }
    result[i] = '\0';

    return result;
}
