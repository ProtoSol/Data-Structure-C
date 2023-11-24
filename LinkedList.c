#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
//Display Function
void LinkedListTraversal (struct node * ptr){
    while (ptr != NULL){
        printf ("Element = %d\n", ptr->data);
        ptr = ptr->next;
    }
}
//Case 1
struct node * InsertBeginning (struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
//Case 2
struct node * InsertBetween (struct node *head, int data, int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i;
    while (i != index -1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}
//Case 3
struct node * InsertEnd (struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
//Case 4
struct node * InsertAfterNode (struct node* head,struct node *prevnode, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}
// Delete Case 1
struct node* DeleteBeginning(struct node* head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
//Delete Case 2
struct node* DeleteBetween(struct node* head, int index){
    struct node *p = head;
    int i = 0;
    while(i < index){
        p = p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}
//Delete Case 3
struct node* DeleteEnd(struct node* head){
    struct node *p = head;
    struct node *q = p->next;
    while (q->next != NULL){
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
//Delete Case 4
struct node* DeleteAfterValue(struct node* head, struct node* P){
    struct node* p = P -> next;
    P -> next = p -> next;
    free(p);
    return head;
}
int main(){
    //alocated in heap
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    //Linking Nodes with values.
    head->data = 31;
    head->next = second;
    second->data = 21;
    second->next = third;
    third->data = 71;
    third->next = fourth;
    //Last one is always Null
    fourth->data = 91;
    fourth->next = NULL;
    //For Insertion
    
    //head = InsertBeginning(head,2);
    //LinkedListTraversal(head);
    
    //head = InsertBetween(head, 1, 1);
    //LinkedListTraversal(head);
    
    //head = InsertEnd(head,99);
    //LinkedListTraversal(head);
    
    //head = InsertAfterNode(head,head,20);
    //LinkedListTraversal(head);

    //For Deletion

    //printf("Before deletion : \n");
    //LinkedListTraversal(head);
    //printf("After deletion : \n");
    //head = DeleteBeginning(head);
    //LinkedListTraversal(head);

    //printf("Before deletion : \n");
    //LinkedListTraversal(head);
    //printf("After deletion : \n");
    //head = DeleteBetween(head, 0);
    //LinkedListTraversal(head);

    //This one works diffrently than the insert at end.
    //printf("Before deletion : \n");
    //LinkedListTraversal(head);
    //printf("After deletion : \n");
    //head = DeleteEnd(head);
    //LinkedListTraversal(head);

    //printf("Before deletion : \n");
    //LinkedListTraversal(head);
    //printf("After deletion : \n");
    //head = DeleteAfterValue(head,head);
    //LinkedListTraversal(head);
    return 0;
}