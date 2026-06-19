bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int* table = calloc(9, sizeof(int));
    for(int i=0; i<boardSize; i++)
    {
        for(int j=0; j<boardColSize[i]; j++)
        {
            if(board[i][j] != '.')
            {
                table[board[i][j] - '1']++;
            }
        }
        for(int z=0; z<9; z++)
        {
            if(table[z]>1)
            {
                return false;
            }
            table[z] = 0;
        }
    }

    for(int k=0; k<boardSize; k++)
    {
        for(int l=0; l<boardColSize[k]; l++)
        {
            if(board[l][k] != '.')
            {
                table[board[l][k] - '1']++;
            }
        }
        for(int y=0; y<9; y++)
        {
            if(table[y]>1)
            {
                return false;
            }
            table[y] = 0;
        }
    }

    for(int c=0; c<9; c+=3)
    {
        for(int d=0; d<9; d+=3)
        {
            for(int a=c; a<c+3; a++)
            {
                for(int b=d; b<d+3; b++)
                {
                    if(board[a][b] != '.')
                    {
                        table[board[a][b] - '1']++;
                    }
                }
            }
            for(int x=0; x<9; x++)
            {
                if(table[x]>1)
                {
                    return false;
                }
                table[x] = 0;
            }
        }
    }
    return true;
}
