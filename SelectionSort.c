#include <stdio.h>
void printarray(int a[], int n){
    int i = 0;
    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
void selectionsort (int a[], int n){
    int t, temp;
    for(int i = 0; i < n; i++){
        t = i;
        for(int j = i+1; j < n; j++){
            if (a[j] < a[t]){
                 t = j;
            }
        }
        temp = a[i];
        a[i] = a[t];
        a[t] = temp;
    }
}
int main(){
    int a[] = {61,42,54,78,12,1};
    int n = 6;
    printarray(a,n);
    selectionsort(a,n);
    printf("\n");
    printarray(a,n);
    return 0;
}