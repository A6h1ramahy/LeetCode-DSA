int compare(const void * a, const void* b)
{
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x<y) - (x>y);
}

int lastStoneWeight(int* stones, int stonesSize) {
    int a;
    qsort(stones,stonesSize,sizeof(int),compare);
    for(int i=0; i<stonesSize-1; i++)
    {
        a = stones[i] - stones[i+1];
        for(int j=i+1; j<stonesSize; j++)
        {
            if(j==stonesSize-1 || a>=stones[j+1])
            {
                stones[j] = a;
                break;
            }
            stones[j] = stones[j+1];
        }
    }
    return stones[stonesSize-1];
}
