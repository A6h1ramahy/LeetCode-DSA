long long countCommas(long long n) {
    long long result = 0;
    long long x = 1000;
    
    while (x <= n) 
    {
        result += (n - x + 1);
        if (x > LLONG_MAX / 1000) {
            break;
        }
        x *= 1000;
    }
    
    return result;
}
