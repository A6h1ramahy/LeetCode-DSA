int totalWaviness(int num1, int num2) {
    int a,j;
    int num = num1;
    int result = 0;
    int digits[6] = {0};
    int digitcount;
    while(num != (num2+1))
    {
        if(num<=99)
        {
            num++;
            continue;
        }
        a = num;
        j = 0;
        while(a!=0)
        {
            digits[j++] = a % 10;
            a = a/10;
        }
        for(int i=0; i<(j-2); i++)
        {
            if((digits[i+1]<digits[i] && digits[i+1]<digits[i+2]) || (digits[i+1]>digits[i] && digits[i+1]>digits[i+2]))
            {
                result++;
            }
        }
        num++;
    }
    return result;
}
