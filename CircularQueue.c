#include<stdio.h>
#define max 6
int Cqueue[max];
int F = -1;
int R = -1;

void Cqueue_insert(int element){
    if(F == -1 && R == -1){
        F = R = 0;
    }
    else if( F == 0 && R == max-1 || F == R + 1){
        printf("Circular Queue is full");
    }
    else if(R == max -1 && F > 0){
        R = 0;
    }
    else{
        R = R+1;
    }
    Cqueue[R] = element;
}

void Cqueue_delete(){
    int e;
    if(F == -1){
        printf ("The queu is Empty");
        return;
    }
    e = Cqueue[F];
    if( F == R){
        F = R = -1;
    }
    else if(F == max - 1){
        F = 0;
    }
    else{
        F = F + 1;
    }
    printf("Element Deleted is %d", e);
}

void Cqueue_display(){
    int i = 0;
    if(F == -1 && R == -1){
        printf("Circular queu is Empty");
    }
    if (F <= R){
        for (int i = F; i <= R; i++){
            printf("%d ",Cqueue[i]);
        }
    }
    else{
        for(i = F; i <= max -1; i++)
            printf("%d ",Cqueue[i]);
        for ( i = 0; i <= R; i++){
            printf("%d ", Cqueue[i]);
        }
    }
}
void main(){
    int choice=1,x;   // variables declaration  
      
    while(choice<4 && choice!=0)   // while loop  
    {  
    printf("\nPress 1: Insert an element");  
    printf("\nPress 2: Delete an element");  
    printf("\nPress 3: Display the element");  
    printf("\nEnter your choice : ");  
    scanf("%d", &choice);  
      
    switch(choice)  {  
        case 1:  
        printf("Enter the element : ");  
        scanf("%d", &x);  
        Cqueue_insert(x);  
        break;  
        case 2:  
        Cqueue_delete();  
        break;  
        case 3:  
        Cqueue_display();  
    }
    }
}  