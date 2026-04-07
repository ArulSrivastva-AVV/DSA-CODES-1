//ch.sc.u4aie25003
//Y's and 0's matrix
#include <stdio.h>

int main() {
    int p, q, i, j;
    scanf("%d %d", &p, &q);
    printf("\n");
    char mat[1000][1000];
    int top = 0, bottom = p - 1;
    int left = 0, right = q - 1;
    char Y= 'Y';

    while (top <= bottom && right >= left) {
        for (i = left; i <= right; i++) {
            mat[top][i] = Y;
        }
        top++;

        for (i = top; i <= bottom; i++) {
            mat[i][right] = Y;
        }
        right--;

        if (top <= bottom) {
            for (i = right; i >= left; i--) {
                mat[bottom][i] = Y;
            }
            bottom--;
        }

        if (left <= right) {
            for (i = bottom; i >= top; i--) {
                mat[i][left] = Y;
            }
            left++;
        }

        if (Y == 'Y') {
            Y = '0';
        } else {
            Y = 'Y';
        }
    }

    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            printf("%c", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}