#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main(){
	struct node *n1,*n2,*n3,*head;
	n1=(struct node*)malloc(sizeof(struct node));
		n2=(struct node*)malloc(sizeof(struct node));
			n3=(struct node*)malloc(sizeof(struct node));
	n1->data=1000;
	n1->next=n2;
	n2->data=2000;
	n2->next=n3;
	n3->data=3000;
	n3->next=NULL;
	head=n1;
	while(head!=NULL){
		printf("%d\n",head->data);
		head=head->next;
	}
}