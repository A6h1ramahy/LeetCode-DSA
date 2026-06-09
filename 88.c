void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(m==0)
    {
        for(int a=0; a<n; a++)
        {
            nums1[a] = nums2[a];
        }
    }
    else if(n==0)
    {
        return;
    }
    else
    {
        int loop = 1;
        int i;
        m--;
        n--;
        for(i=nums1Size-1; i>=0 && loop==1; i--)
        {
            if(nums1[m]<nums2[n])
            {
                nums1[i] = nums2[n--];
            }
            else
            {
                nums1[i] = nums1[m--];
            }
            if(!(m>=0 && n>=0))
            {
                loop = 0;
            }
        }
        if(m==-1)
        {
            for(int j=i; j>=0; j--)
            {
                nums1[j] = nums2[n--];
            }
        }
        else
        {
            for(int k=i; k>=0; k--)
            {
                nums1[k] = nums1[m--];
            }            
        }
    }
}
