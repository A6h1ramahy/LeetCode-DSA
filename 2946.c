bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    for(int i = 0; i < matSize; i++) {
        int cols = matColSize[i];
        int shift = k % cols;

        for(int j = 0; j < cols; j++) {
            int idx;

            if(i % 2 == 0) {
                // left shift
                idx = (j + shift) % cols;
            } else {
                // right shift
                idx = (j - shift + cols) % cols;
            }

            if(mat[i][j] != mat[i][idx]) {
                return false;
            }
        }
    }
    return true;
}