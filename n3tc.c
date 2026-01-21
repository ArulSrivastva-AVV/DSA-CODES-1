//time complexity of o(n^3)
//  ch.sc.u4aie25003


#include <stdio.h>

int main(){
    int n,m;
    printf("Enter number of rows and columns of matrix1: ");
    scanf("%d %d", &n, &m);
    int arr1[n][m];
    int o, p;
    printf("Enter number of rows and columns of matrix2: ");
    scanf("%d %d", &o, &p);
    int arr2[o][p];
    int result[n][p];
    if (m != o) {
        printf("\nMatrix multiplication not possible\n");
        return 0;
    }
    printf("\nEnter elements of matrix1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter elements of matrix2:\n");
    for (int i = 0; i < o; i++) {
        for (int j = 0; j < p; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
            for (int k = 0; k < m; k++) {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("\nResultant matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}