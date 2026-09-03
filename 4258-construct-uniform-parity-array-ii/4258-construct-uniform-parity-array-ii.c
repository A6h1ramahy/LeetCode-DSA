bool uniformArray(int* nums1, int nums1Size) {
    int even = 1;
    int odd = 1;
    for(int i=0; i<nums1Size; i++)
    {
        if(nums1[i]%2==1)
        {
            even = 0;
        }
        else
        {
            odd = 0;
        }
    }
    if(odd || even)
    {
        return true;
    }
    int i = 0;
    while(nums1[i]%2!=0)
    {
        i++;
    }
    even = nums1[i];
    for(i++; i<nums1Size; i++)
    {
        if(nums1[i]%2==0 && nums1[i]<even)
        {
            even = nums1[i];
        }
    }

    for(i=0; i<nums1Size; i++)
    {
        if(nums1[i]%2!=0 && nums1[i]<even)
        {
            return true;
        }
    }
    return false;
}