int search(int* nums, int numsSize, int target) {
    int min = 0;
    numsSize--;      

    while (min <= numsSize) {
        int mid = min + (numsSize - min) / 2;

        if (nums[mid] == target) {
            return mid;
        }
        else if (nums[mid] > target) {
            numsSize = mid - 1;
        }
        else {
            min = mid + 1;
        }
    }
    return -1;
}
