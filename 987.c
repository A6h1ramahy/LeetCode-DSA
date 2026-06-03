/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>
#include <limits.h>

typedef struct {
    int col;
    int row;
    int val;
} NodeInfo;

NodeInfo nodes[1001];
int nodeCount;

void dfs(struct TreeNode* root, int row, int col) {
    if (root == NULL)
        return;

    nodes[nodeCount].col = col;
    nodes[nodeCount].row = row;
    nodes[nodeCount].val = root->val;
    nodeCount++;

    dfs(root->left, row + 1, col - 1);
    dfs(root->right, row + 1, col + 1);
}

int cmp(const void* a, const void* b) {
    NodeInfo* x = (NodeInfo*)a;
    NodeInfo* y = (NodeInfo*)b;

    if (x->col != y->col)
        return x->col - y->col;

    if (x->row != y->row)
        return x->row - y->row;

    return x->val - y->val;
}

int** verticalTraversal(struct TreeNode* root,
                        int* returnSize,
                        int** returnColumnSizes) {
    nodeCount = 0;

    dfs(root, 0, 0);

    qsort(nodes, nodeCount, sizeof(NodeInfo), cmp);

    int** result = (int**)malloc(nodeCount * sizeof(int*));
    *returnColumnSizes = (int*)malloc(nodeCount * sizeof(int));

    int colCount = 0;
    int i = 0;

    while (i < nodeCount) {
        int currentCol = nodes[i].col;
        int start = i;

        while (i < nodeCount && nodes[i].col == currentCol)
            i++;

        int size = i - start;

        result[colCount] = (int*)malloc(size * sizeof(int));
        (*returnColumnSizes)[colCount] = size;

        for (int j = 0; j < size; j++) {
            result[colCount][j] = nodes[start + j].val;
        }

        colCount++;
    }

    *returnSize = colCount;
    return result;
}
