int removeElement(int* nums, int numsSize, int val) {
    int first = 0;
    int last = numsSize - 1;

    while (first <= last) {
        if (nums[first] == val) {
            nums[first] = nums[last];
            last--;
        }
        else {
            first++;
        }
    }

    return first;
}
