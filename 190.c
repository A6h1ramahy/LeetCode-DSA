int reverseBits(int n) {
    int result = 0;
    for(int i=31; i>=0; i--)
    {
        if(n%2==1)
        {
            result += pow(2,i);
        }
        n /= 2;
    }
    return result;
}

