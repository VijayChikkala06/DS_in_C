#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int data;
    struct queue *next;
} Q;

Q *front = NULL, *rear = NULL;

void enqueue(int info) {
    Q *newnode = (Q*)malloc(sizeof(Q));
    if(newnode == NULL) {
        printf("Memory not allocated..\n");
        return;    
    }
    newnode->data = info;
    newnode->next = NULL;
    if(rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("Node is inserted..\n");
}

void dequeue() {
    Q *temp;
    temp = front;
    if(front == NULL) {
        printf("\nQueue is empty.\n");
        return;
    } else {
        front = front->next;
        free(temp);
    }
    if(front == NULL) {
        rear = NULL;
    }
    printf("Node is deleted.\n");
}

void display() {
    Q *temp = front;
    if (front == NULL) {
        printf("\nQueue is Empty!!!\n");
        return;
    }
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    printf("Rear\n");
}

void isempty() {
    if(front == NULL)
        printf("Queue is empty\n");
    else
        printf("No. Queue is not empty\n");
}

void isfull() {
    printf("Queue is never full (for a linked list implementation).\n");
}

int main() {  
    int choice, info;
    while(1) {
        printf("INDEX\n");
        printf("1.Enqueue\n2.Display\n3.isEMPTY\n4.isFULL\n5.Dequeue\n6.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
                printf("Enter data into queue: ");
                scanf("%d", &info);
                enqueue(info);
                break;
            case 2: 
                display();
                break;
            case 3: 
                isempty();
                break;
            case 4: 
                isfull();
                break;
            case 5: 
                dequeue();
                break;
            case 6: 
                printf("Exited successfully\n");
                exit(0);
        }
    }
}
