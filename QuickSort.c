#include <stdio.h>

int partition(int arr[], int start, int end);

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void Display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    do{
        while (arr[i] <= pivot){
            i++;
        }
        while (arr[j] > pivot){
            j--;
        }
        if (i < j){
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);
    swap(&arr[low], &arr[j]);
    return j;
}

void QuickSort(int arr[], int low, int high){
    int j;
    if (low < high){
        j = partition(arr, low, high);
        QuickSort(arr, low, j - 1);
        QuickSort(arr, j + 1, high);
    }
}

int main(){
    int n, s;
    printf("Enter The Size Of The Array : \n");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array size %d : \n",n);
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    Display(array, n);
    QuickSort(array, 0, n - 1);
    Display(array, n);
}
