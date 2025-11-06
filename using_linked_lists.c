#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
int data;
struct stack *next;
}STACK;

STACK *top=NULL;

int count=0;

void push(int);

int pop();

int peek();

void display();

void push(int info)
{
STACK *newnode=(STACK*)malloc(sizeof(STACK));
if(newnode==NULL)
{
printf("Memory not allocated");
return;
}
newnode->data=info;
newnode->next=NULL;
if(top==NULL)
top=newnode;
else
{
newnode->next=top;
top=newnode;
}
count++;
printf("%d is pushed to stack\n",info);
}

int pop()
{
int x;
if(top==NULL){
printf("Stack is underflow\n");
return 0;
}
else
{
STACK *temp=top;
top=top->next;
x=temp->data;
count--;
free(temp);
return x;
}
}

int peek()
{
if(top==NULL){
printf("Stack is empty");
return 0;
}
else
return top->data;
}

void display()
{
if(top==NULL)
printf("Stack is empty\n");
else
{
STACK *temp=top;
printf("\n***Stack elements are***\n");
while(temp!=NULL)
{
printf("\t%d\n",temp->data);
temp=temp->next;
}
}
}


int main()
{
int ch,x;
do
{
printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
 switch(ch)
 {
 case 1:
 printf("\nEnter element: ");
 scanf("%d",&x);
 push(x);
 break;
 case 2:
 x=pop(x);
 if(x!=0)
 printf("popped element is %d\n",x);
 break;
 case 3: x=peek();
 if(x!=0)
 printf("the top most element is %d\n",x);
 break;
 case 4:display();
 break;
 case 5: printf("Thank you!!!!");
 exit(0);
 break;
 default :printf("Invalid choice\n");
 }
 }while(1);
 return 0;
 }
 
 
 
 