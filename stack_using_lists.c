#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
	int data;
	struct stack *next;
}STACK;

void push(int);
int pop();
int peek();
void display();

STACK *top=NULL;
int count = 0;

void push(int info){
	STACK *newnode = (STACK*)malloc(sizeof(STACK));
	if(newnode== NULL){
		printf("Memory not allocated..");
		return;
	}
	newnode->data=info;
	newnode->next=NULL;
	if(top==NULL){
		top=newnode;
	}
	else{
		newnode->next=top;
		top=newnode;
	}
	count++;
	printf("%d is pushed into the stack ");
}

int pop(){
   if(top==NULL){
   	printf("Stack overflow..");
   }
   else{
   	STACK *temp=top;
   	top=top->next;
   	int ele=temp->data;
   printf("%d is popped from the stack");
   count--;
   free(temp);
   return ele;
  }
 }
 
int peek(){
	if(top== NULL){
		printf("Stack is empty");
	}
	else return top->data;
}

void display(){
	if(top==NULL){
		printf("Stack is empty");
	}
	else {
		STACK *temp=top;
		while(temp!=NULL){
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}

int main(){
	int choice,info;
	while(1){
	printf("****Contents****\n");
	printf("1.push\n2.pop\n3.peek\n4.Display\n5.Exit\n");
	printf("Enter youe choice: ");
	scanf("%d",choice);
	}
	switch(choice){
		case 1:
		printf("Enter the data into the stack");
		scanf("%d",&info);
		push(info);
		break;
		case 2:pop();break;
		case 3:peek();break;
		case 4:display();break;
		case 5:printf("Exited successfully");
		    exit(0);
	
	}
}













