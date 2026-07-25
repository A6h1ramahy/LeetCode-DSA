int maxProduct(int n) {
    int max = 0, secmax = 0, a;
    while(n>0)
    {
        a = n%10;
        n = n/10;   
        if(a > max)
        {
            secmax = max;
            max = a;
        }
        else if(a > secmax)
        {
            secmax = a;
        }
    }
    return secmax*max;
}
