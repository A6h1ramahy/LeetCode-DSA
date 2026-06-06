#include <strings.h>

int romanToInt(char* s) {
    int len = strlen(s);
    char a;
    int result = 0, cur = 0, prev;
    for(int i=(len-1); i>=0; i--)
    {
        prev = cur;
        a = s[i];
        if(a=='I')
        {
            cur = 1;
        }
        else if(a=='V')
        {
            cur = 5;
        }
        else if(a=='X')
        {
            cur = 10;
        }
        else if(a=='L')
        {
            cur = 50;
        }
        else if(a=='C')
        {
            cur = 100;
        }
        else if(a=='D')
        {
            cur = 500;
        }
        else if(a=='M')
        {
            cur = 1000;
        }

        if(cur>=prev)
        {
            result = result + cur;
        }
        else
        {
            result = result - cur;
        }
    }
    return result;
}

