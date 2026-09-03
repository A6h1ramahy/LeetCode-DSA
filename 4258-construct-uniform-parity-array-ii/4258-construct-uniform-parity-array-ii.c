bool uniformArray(int* nums1, int nums1Size) {
    int odd = INT_MAX;
    int even = INT_MAX;

    for (int i=0; i<nums1Size; i++) 
    {
        if (nums1[i]%2 == 0 && nums1[i]<even) 
        {
            even = nums1[i];
        } 
        else if (nums1[i]%2 != 0 && nums1[i]<odd)
        {
            odd = nums1[i];
        }
    }

    if (odd == INT_MAX)
        return true;

    if (even == INT_MAX)
        return true;

    return odd < even;
}