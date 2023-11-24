#include<stdio.h>
void printarray(int a[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void bubblesort(int a[], int n){
    int i, j, t;
    int isSorted = 0;
    for(i = 0; i < n - 1; i++){
        isSorted = 1;
        for(j = 0; j < n-i-1; j++){
            if (a[j] > a[j+1]){
                t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
                isSorted = 0;
            }
        }
        if (isSorted == 1){
            printf("\nAlready sorted\n");
            return;
        }
    }
}
void main(){
    int a[] = {1,2,3,4,5,6};
    int n = 6;
    printarray(a,n);
    bubblesort(a,n);
    printf("\n");
    printarray(a,n);
}
