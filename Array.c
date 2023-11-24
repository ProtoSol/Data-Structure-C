#include <stdio.h>

int partition (int arr[],int start, int end);

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void Display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf ("%d ",arr[i]);        
    }
    printf("\n");
}

void BubbleSort(int arr[] , int size){
    int temp;
    for (int i = 0; i < size; i++){
        for(int j = 0 ; j < size; j++){
            if (arr[j] > arr[j+1]) {
                    swap( &arr[j] , &arr[j+1]);
                }
        }
    }
    for(int i = 0; i < size; i++){
        printf ("%d ",arr[i]);        
    }

}

// void QuickSort(int arr[], int low, int high){
//     int j = partition(arr, low, high);
//     QuickSort(arr, low, j);
//     QuickSort(arr, j+1, high);
// }

// int partition (int arr[],int low, int high){
//     int pivot = arr[low];
//     int i = low;
//     int j = high;
//     while (i < j){
//         do { i++; }
//         while (arr[i] > pivot);
//         do { j++; }
//         while (arr[j] < arr[i]);
//         swap(&arr[i], &arr[j]);
//     }
//     swap(&arr[low], &arr[j]);
//     return j;
// }

int BinarySearch(int arr[], int n, int key){
    int low = 0;
    int high = n-1;
    while(low < high){
        int mid = (low + high)/2;
        if(arr[mid] == key) return mid;
        else if (arr[mid] > key) low = mid + 1;
        else high = mid - 1;
    }
    return -1 ;
}

int main () {
    int n,s;
    printf("Enter The Size Of The Array : \n");
    scanf("%d",&n);
    int array[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
    // Display(array,n);
    // printf("\n");
    // QuickSort(array, 0, n);
    Display(array,n);
    BubbleSort(array, n);
    printf("\n Enter the number to Find : \n");
    scanf("%d",&s);
    int m = BinarySearch(array, n, s);
    if (m == 0){
        printf("Not found in the Provided Array");
    }
    else{
        printf("Item found at location : %d", m);
    }
}