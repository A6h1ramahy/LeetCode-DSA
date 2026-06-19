int largestAltitude(int* gain, int gainSize) {
    int cur = 0,result = 0;
    for(int i=0; i<gainSize; i++)
    {
        cur = cur+gain[i];
        if(cur>result)
        {
            result = cur;
        }
    }
    return result;
}
