#include<stdio.h>
#define max 100
//The functions that will be used.
void arrayrot(int[],int,int);
//Main Function for array input.
void main()
{
    int A[max],d,n,i;
    printf("Enter The Size of the Array :\n");
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
       printf("Enter the value of %d Element : ",i);
       scanf("%d",&A[i]);
    }
    printf("The Entered Array is : \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    //now I have to make a function for the array rotation.
    printf("\nEnter the postion from which the array will be rotated : \n");
    scanf("%d",&d);
    arrayrot(A,n,d);

}
void arrayrot(int A[],int n,int d)
{
    int i = 0,temp[max],t=0;
    for ( i = 0; i < d; i++)
    {
        temp[i] = A[i];
    }
    for (i=0; i < n; i++)
    {
        A[i] = A[d+i];
    }
    for ( i = n-d; i < n; i++)
    {
       A[i] = temp[t];
       printf("%d it is test ",temp[t]);
       t++;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d, ", A[i]);
    }
    
    
}