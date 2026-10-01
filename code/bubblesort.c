#include <stdio.h>
int main(){
    printf("bubble sort\n");
    int arr1[5]={4,3,5,2,1};
    int temp;
    int n=5;
    int i,j;

    for(int i=n;i>1;i--){
        for(int j=0;j<i;j++){
            if (arr1[j]>arr1[j+1]){
            temp=arr1[j];
            arr1[j]=arr1[j+1];
            arr1[j+1]=temp;
        }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);

    }
    return 0;
}
