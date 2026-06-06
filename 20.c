#include <strings.h>

void push(char a, char* stack, int *point, int len)
{
    if((*point)<len)
    {
        stack[(*point)++] = a;
    }
}

char pop(char* stack, int *point)
{
    if(*point==0)
    {
        return '#';
    }
    char b = stack[--(*point)];
    return b;
}

bool isValid(char* s) {
    int len = strlen(s);
    char stack[len];
    int point = 0;
    char a;
    for(int i=0; i<len; i++)
    {
        a = s[i];
        if(a=='(' || a=='{' || a=='[')
        {
            push(a, stack, &point, len);
        }
        else if (a==')' && !(pop(stack, &point) == '('))
        {
            return false;
        }
        else if(a=='}' && !(pop(stack, &point) == '{'))
        {
            return false;
        }
        else if(a==']' && !(pop(stack, &point) == '['))
        {
            return false;
        }
    }
    if(point==0)
    {
        return true;
    }
    return false;
}
