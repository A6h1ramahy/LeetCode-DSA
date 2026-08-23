bool checkDivisibility(int n) {
    int sum = 0;
    int prod = 1;
    int num = n;
    while(n!=0)
    {
        sum += n%10;
        prod *= n%10;
        n /= 10;
    }
    sum += prod;

    return num % sum == 0;
}
