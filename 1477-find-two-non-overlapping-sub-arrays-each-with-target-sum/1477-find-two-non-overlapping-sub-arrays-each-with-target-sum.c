int minSumOfLengths(int* arr, int arrSize, int target) {
    int INF = INT_MAX / 2;
    int best[arrSize];
    int l = 0;
    int sum = 0;
    int min = INF;
    int result = INF;

    for (int r = 0; r < arrSize; r++) 
    {
        sum += arr[r];
        while (sum > target) 
        {
            sum -= arr[l];
            l++;
        }

        if (sum == target) 
        {
            int len = r - l + 1;
            if (l > 0) 
            {
                if(result > len + best[l - 1])
                {
                    result = len + best[l - 1];
                }
            }

            if (len < min)
            {
                min = len;
            }
        }

        best[r] = min;
    }

    if(result == INF)
    {
        return -1;
    }
    return result;
}