int longestSubstring(char* s, int k) {
    int n = strlen(s);
    int result = 0;

    for (int target = 1; target <= 26; target++) 
    {
        int freq[26] = {0};
        int l = 0, r = 0;
        int unique = 0;
        int count = 0;

        while (r < n) 
        {
            int idx = s[r] - 'a';
            if (freq[idx] == 0)
            {
                unique++;
            }
            freq[idx]++;

            if (freq[idx] == k)
            {
                count++;
            }
            r++;

            while (unique > target) 
            {
                int remove = s[l] - 'a';
                if (freq[remove] == k)
                {
                    count--;
                }
                freq[remove]--;

                if (freq[remove] == 0)
                {
                    unique--;
                }
                l++;
            }

            if (unique == target && unique == count) 
            {
                int len = r - l;
                if (len > result)
                {
                    result = len;
                }
            }
        }
    }
    return result;
}