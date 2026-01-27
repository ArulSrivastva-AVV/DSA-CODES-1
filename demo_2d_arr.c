/* Program to demonstrate 2D array 
ch.sc.u4aie25003
31/12/2025*/

#include<stdio.h>


int main() {
    int i;
    int arr[2][3]={{1,2,3},{4,5,6}};
    printf("Before modification \n");
    for(i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
    arr[1][2]=10;
    printf("After modification \n");
    for(i=0; i<2; i++) {
        for(int j=0; j<3; j++) {
            printf("%d \t", arr[i][j]);
        }
        printf("\n");
    }
}