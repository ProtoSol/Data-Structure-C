#include<stdio.h>
void printarray(int a[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void insertionsort(int a[], int n){
    int key, j;
    for(int i = 0; i < n; i++){
        key = a[i];
        j = i-1;
        while(j >= 0 && a[j] > key){
            a[j+1] = a[j];
            j --;
        }
        a[j+1] = key;
    }
}
void main(){
    int a[] = {61,42,54,78,12,1};
    int n = 6;
    printarray(a,n);
    insertionsort(a,n);
    printf("\n");
    printarray(a,n);
}
