#include <stdio.h>

#define MAXSIZE 5

int items[MAXSIZE];
int top = -1;

void push(int item);
int pop();
void display();

int main() {
    int choice, item;

    do {
        printf("\n\n----- Stack Operations Menu -----");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the item to be pushed: ");
                scanf("%d", &item);
                push(item);
                break;

            case 2:
                item = pop();
                if (item != -1) {
                    printf("\nThe popped item is: %d", item);
                }
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nExiting the program...");
                break;

            default:
                printf("\nInvalid choice! Please select a valid option.");
        }
    } while (choice != 4);

    return 0;
}

void push(int item) {
    if (top == MAXSIZE - 1) {
        printf("\nStack is full!");
    } else {
        top++;
        items[top] = item;
        printf("\n%d has been pushed.", item);
    }
}

int pop() {
    int item;
    if (top == -1) {
        printf("\nStack is empty!");
        return -1;
    } else {
        item = items[top];
        top--;
        return item;
    }
}

void display() {
    if (top == -1) {
        printf("\nStack is empty!");
    } else {
        printf("\nThe stack is: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", items[i]);
        }
    }
}