//time complexity of O(log n)
//  ch.sc.u4aie25003

#include<stdio.h>

int main(){
    int max;
    int target;
    int mid=0;
    int n;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int arr[n];
    printf("enter the array in sorted manner");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the target element to be searched");
    scanf("%d",&target);
    int left=0;
    int right=n-1;      
    while(left<=right){
        mid=(left+right)/2;
        if(arr[mid]==target){
            printf("Element found in the index %d",mid);
            return 0;
        }
        else if(arr[mid]<target){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
}