#include <stdio.h>
#include<stdlib.h>
#define SIZE 5

void enQueue(int);
void deQueue();
void display();

int items[SIZE], front = -1, rear = -1;
int count=0;

void enQueue(int value) {
  if (rear == SIZE - 1)
    printf("\nQueue is Full!!\n");
  else {
    if (front == -1)
      front = 0;
    rear++;
    items[rear] = value;
    printf("Element is inserted..\n");
    count++;
  }
}

void deQueue() {
  if (front == -1||front>rear)
    printf("\nQueue is Empty!!");
  else {
    printf("\nDeleted : %d\n", items[front]);
    front++;
    if (front > rear)
      front = rear = -1;
  }
}

void display() {
  if (rear == -1)
    printf("\nQueue is Empty!!!\n");
  else {
    int i;
	for (i = front; i <= rear; i++)
      printf("%d ->", items[i]);
  }
  printf("Rear");
  printf("\n");
}

void isempty(){
	if(front==-1&&rear==-1)
	printf("List is empty\n");
	else
	printf("No.List is not empty\n");
}

void isfull(){
	if(rear==SIZE-1)
	printf("List is full\n");
	else 
	printf("No.List is not full\n");
}

int main() {  
int choice,info;
   while(1){
  printf("INDEX\n");
  printf("1.Enqueue\n2.Display\n3.isEMPTY\n4.isFULL\n5.Dequeue\n6.Exit\n");
  printf("Enter your choice:");
  
  scanf("%d",&choice);
  switch(choice){
  	case 1: 
  	printf("Enter data into queue:");
  	scanf("%d",&info);
  	enQueue(info);
  	break;
  	case 2 : display();
  	break;
  	case 3 : isempty();break;
  	case 4 : isfull();break;
  	case 5 : deQueue();break;
  	case 6 : printf("Exited successfully");
  	exit(0);
  }
}
} 
