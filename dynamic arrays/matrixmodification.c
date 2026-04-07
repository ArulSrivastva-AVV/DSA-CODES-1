
//ch.sc.u4aie25003
//Array-9: matrix modify
#include <stdio.h>

int main() {
    int r,c,i,j,k;
    scanf("%d %d",&r,&c);
    int arr[r][c], arrTemp[r][c];
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            scanf("%d",&arr[i][j]);
            arrTemp[i][j]=arr[i][j];
        }
    }
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            if(arr[i][j]==1) {
                for(k=0;k<c;k++) arrTemp[i][k]=1;
                for(k=0;k<r;k++) arrTemp[k][j]=1;
            }
        }
    }
    printf("\n");
    for(i=0;i<r;i++) {
        for(j=0;j<c;j++) {
            printf("%d ",arrTemp[i][j]);
        }
        printf("\n");
    }
    return 0;
}