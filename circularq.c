//Circular Queue Implementation
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

//Function Prototypes
void enq(int);
int deq();
void display();
//Global Declaration
int queue[SIZE];
int front = -1, rear = -1;

int main() {
    int ch, x;
    while (1) {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: 
                printf("Enter an element into the queue: ");
                scanf("%d", &x);
                enq(x); 
                break;
            case 2: 
                x = deq();
                if (x != -1)
                    printf("%d is removed from Queue\n", x);
                break;
            case 3: 
                display(); 
                break;
            case 4: 
            	printf("BYE!!");
                exit(0);
            default: 
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void enq(int ele) {
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
	{
        printf("Queue is full\n");
        return;
    }
    else{
    rear = (rear + 1) % SIZE;
    if (front == -1) // First element insertion
        front = 0;
    queue[rear] = ele;
    printf("%d is placed in Queue\n", ele);
  } 
}

int deq() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int ele = queue[front];
    if (front == rear) {
        // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }

    return ele;
}

void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:");
    int i = front;
    while (1) {
        printf("\t%d", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}