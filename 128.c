typedef struct {
    int key;
    UT_hash_handle hh;
} HashNode;

int longestConsecutive(int* nums, int numsSize) {
    if (numsSize == 0)
        return 0;

    HashNode *set = NULL;
    HashNode *node;

    for (int i = 0; i < numsSize; i++) {
        HASH_FIND_INT(set, &nums[i], node);

        if (node == NULL) {
            node = (HashNode *)malloc(sizeof(HashNode));
            node->key = nums[i];
            HASH_ADD_INT(set, key, node);
        }
    }

    int longest = 0;

    HashNode *curr, *tmp;

    HASH_ITER(hh, set, curr, tmp) {

        int prev = curr->key - 1;

        HASH_FIND_INT(set, &prev, node);

        if (node != NULL)
            continue;

        int length = 1;
        int current = curr->key;

        while (1) {
            int next = current + 1;

            HASH_FIND_INT(set, &next, node);

            if (node == NULL)
                break;

            current++;
            length++;
        }

        if (length > longest)
            longest = length;
    }

    HASH_ITER(hh, set, curr, tmp) {
        HASH_DEL(set, curr);
        free(curr);
    }

    return longest;
}
