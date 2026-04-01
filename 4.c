double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *final = malloc((nums1Size + nums2Size)*sizeof(int));
    int n1=0, n2=0, n=0;

    while(n1!=nums1Size && n2!=nums2Size)
    {
        if(nums1[n1]>nums2[n2])
        {
            final[n++] = nums2[n2++];
        }
        else
        {
            final[n++] = nums1[n1++];
        }
    }
    if(n1==nums1Size)
    {
        while(n2 != nums2Size)
        {
            final[n++] = nums2[n2++];
        }
    }
    else
    {
        while(n1 != nums1Size)
        {
            final[n++] = nums1[n1++];
        }
    }

    if(n%2==0)
    {
        double a = (final[n/2]+final[(n/2)-1])/2.0;
        free(final);
        return a;
    }
    else
    {
        double a = final[n/2];
        free(final);
        return a;
    }
}