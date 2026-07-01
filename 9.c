bool isPalindrome(int x) {
    long long a = 0;
    int b;
    long long y = x;
    if(x<0)
    {
        return false;
    }
    while(x != 0)
    {
        b = x%10;
        x = x/10;
        a = (a*10) + b;
    }
    if(y != a)
    {
        return false;
    }
    return true;
}

