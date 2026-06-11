bool checkValidString(char* s) {
    int open[105];
    int star[105];

    int topOpen = -1;
    int topStar = -1;

    for(int i = 0; s[i] != '\0'; i++) {

        if(s[i] == '(') {
            open[++topOpen] = i;
        }
        else if(s[i] == '*') {
            star[++topStar] = i;
        }
        else { // ')'

            if(topOpen >= 0) {
                topOpen--;
            }
            else if(topStar >= 0) {
                topStar--;
            }
            else {
                return false;
            }
        }
    }

    while(topOpen >= 0 && topStar >= 0) {

        if(open[topOpen] > star[topStar]) {
            return false;
        }

        topOpen--;
        topStar--;
    }

    return topOpen == -1;
}
