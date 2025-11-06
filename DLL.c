#include<stdio.h>
#include<stdlib.h>
struct node {
	struct node *prev;
	int data;
	struct node *next;
};
struct node *head=NULL,*end=NULL;

struct node *createnode();
void create_list();
void display();
int count=0;

struct node *createnode(){
	int info;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL){
		printf("Can't allocate memory");
		return newnode;
	}
	printf("Enter data into  a node:");
	scanf("%d",&info);
	newnode->data=info;
	newnode->prev=NULL;
	newnode->next=NULL;
	return newnode;
}

void create_list(){
	struct node *newnode=createnode();
	if(head== NULL){
		head =end =newnode;
	}
	else {
		end->next=newnode;
		newnode->prev=end;
		end=newnode;
	}
	count++;
	printf("List is created");
}

void display(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	else{
	temp=head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf(" End Null\n");
}
}

void reverselist(){
	struct node *temp;
	if(head==NULL){
		printf("List is empty");
		return;
	}
	temp=end;
	while(temp!=NULL){
		printf("%d",temp->data);
		temp=temp->prev;
	}
	printf("Head Null\n");
}
int main() {
    int ch;
    while(1) {
        printf("\n***CONTENTS***\n");
        printf("Select any number to get corresponding result:\n");
        printf("1.Createnode\n2.create list\n3 Display\n4.Reverse a list\n5.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch); 
        switch(ch) {
            case 1: createnode(); break;
            case 2: create_list(); break;
            case 3: display();break;
            case 4: reverselist();break;
            case 5: printf("Exited successfully\n"); return 0;
            default: printf("\n--Invalid choice--\n"); break;
        }
    }
}
