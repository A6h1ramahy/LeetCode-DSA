int reverse(int x){
    int result=0, b;
    while(x != 0)
    {
        b = x%10;
        x = x/10;
        if(result > INT_MAX/10 
        || result < INT_MIN/10 
        || (result == INT_MIN/10 && b<-8) 
        || (result == INT_MAX/10 && b > 7))
        {
            return 0;
        }
        result = (result*10) + b;
    }
    return result;
}

