#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
//Display Function
void CLinkedListTraversal (struct node * head){
    struct node * ptr = head;
    do {
        printf ("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
    while (ptr != head);
}
//Now we go to the insert part of the Circular Linked list
struct node * InsertBeginning (struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node * p = head->next;
    while (p -> next != head){
        p = p->next;
    }
    p -> next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
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
struct node * InsertEnd (struct node *head, int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node* p = head;
    while(p->next != head){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
// For Deletion of node in circular linked list
// Delete Case 1

//It somehow Works I guess...
struct node* DeleteBeginning(struct node* head){
    struct node * p = head;
    do{
        p = p->next;
    }
    while(p->next != head);
    struct node * ptr = p->next;
    p-> next = ptr -> next;
    free(ptr);
    head = p -> next;
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
    while (q->next != head){
        q = q->next;
        p = p->next;
    }
    p->next = head;
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
    // Linking Nodes with values.
    head->data = 31;
    head->next = second;
    second->data = 21;
    second->next = third;
    third->data = 71;
    third->next = fourth;
    //Last one is always always the head of the circular linked list
    fourth->data = 91;
    fourth->next = head;
    // CLinkedListTraversal(head);
    // head = InsertBeginning(head, 1);
    // CLinkedListTraversal(head);
    // head = DeleteBeginning(head);
    // CLinkedListTraversal(head);
    
    // The User can easily make the switch case to implemend these functions and creat a program for Circular Linked List
    return 0;
}