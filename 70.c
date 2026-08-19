int climbStairs(int n) {
    if(n<=2)
    {
        return n;
    }
    int first = 1;
    int sec = 2;
    int cur;
    for(int i=3; i<=n; i++)
    {
        cur = first+sec;
        first = sec;
        sec = cur;
    }
    return sec;
}
