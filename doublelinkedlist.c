#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL, *end = NULL;
int count = 0;

struct node *createnode();
void create_list();
void display();
void reverselist();

struct node *createnode(){
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Can't allocate memory\n");
        return newnode;
    }
    printf("Enter data into a node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

void create_list() {
    struct node *newnode;
        newnode = createnode();
        if (head == NULL) {
            head = end = newnode;
        } else {
            end->next = newnode;
            newnode->prev = end;
            end = newnode;
        }
        count++;
    printf("Node is created\n");
}

void display() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
        temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("End\n");
    }
}

void reverselist() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = end;
     printf("Head");
    while (temp != NULL) {
        printf("<- %d", temp->data);
        temp = temp->prev;
    }
   
}

void insert_at_beginning(){
	struct node *newnode=createnode();
	if(head==NULL){
		head=end=newnode;
	}
	else{
		head->prev=newnode;
		newnode->next=head;
		head=newnode;
	}
	count++;
	printf("Node is added at beginning");
}

void insert_at_end(){
	struct node*newnode=createnode();
	if(head==NULL){
		head=end=newnode;
	}
	else {
		newnode->prev=end;
		end->next=newnode;
		end=newnode;
		
	}
	count++;
}

 void insert_at_any_position(){
	struct node  *newnode,*temp,*curr;
	int pos,i;
	printf("\nEnter the position u want to insert:");
	scanf("%d",&pos);
	if(pos<1||pos>count+1){
		printf("Invalid position");
		return;
	}
	if(pos==1){
		insert_at_beginning();
		return;
	}
	else if(pos==count+1){
		insert_at_end();
		return;
	}
	newnode=createnode();
	curr=head;
	for(i=1;i<pos;i++){
		temp=curr;
		curr=curr->next;
	}
	newnode->next=curr;
	newnode->prev=temp;
	curr->prev=newnode;
	temp->next=newnode;
	count++;
}

void delete_custom(){
	struct node *temp,*curr;
	int pos,i;
	if(head==NULL){
 		printf("Nothing to delete.");
 		return;
	}
	printf("Enter the position u want to delete: ");
	scanf("%d",&pos);
	if(pos<1||pos>count){
		printf("Invalid position");
		return;
	}
	if(pos==1){
		temp=head;
		head = head->next;
		if(head==NULL){
			end=NULL;
		}
		else{
			head->prev=NULL;
		}
		free(temp);
		count--;
	}
	else if(pos==count){
		temp=end;
		end=end->prev;
		if(end==NULL){
			head=NULL;
		}
		else{
		end->next=NULL;	
		}
	free(temp);
	count--;	
	}
	else{
	curr=head;
	for(i=1;i<pos;i++){
		temp=curr;
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next->prev=temp;
	free(curr);
	count--;
  }
  printf("Node is deleted..");
}

void search() {
    int key, pos = 1, found = 0;
    struct node *curr = head;
    
    if(head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    
    printf("Enter the element you wanna search: ");
    scanf("%d", &key);
    
    while(curr != NULL) {
        if(curr->data == key) {
            found = 1;
            break;
        }
        curr = curr->next;
        pos++;
    }
    
    if(!found) {
        printf("\nElement not found in the linked list.\n");
    }
    else 
     printf("\nThe given element %d is found at position %d\n", key, pos);
}

void replace_node() {
    int pos, new_data, i;
    struct node *temp;

    if (head == NULL) {
        printf("\nThe list is empty. No node to replace.\n");
        return;
    }

    printf("\nEnter the position of the node to replace : ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count) {
        printf("\nInvalid position! The list has only %d nodes.\n", count);
        return;
    }

    printf("\nEnter the new data: ");
    scanf("%d", &new_data);
    temp = head;
    for (i = 1; i < pos; i++) { 
        temp = temp->next;
    }

    printf("\nReplacing node at position %d (old data: %d) with new data: %d\n", pos, temp->data, new_data);
    temp->data = new_data;
}
int main() {
    int ch;
    while (1) {
        printf("\n***CONTENTS***\n");
        printf("Select any number to get corresponding result:\n");
        printf("1. Create list\n2. display\n3.Reverse a list\n4.Insert at beginning\n5.Insert at end\n6.insert at any position\n7.delete at any pos\n8.size of the list\n9.Searching\n10.Replace node\n11.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch); 
        switch (ch) {
            case 1:create_list(); 
                break;
            case 2: display(); 
               break;
            case 3: reverselist();  
                break;
            case 4: insert_at_beginning();
                 break;
            case 5: insert_at_end();
                 break;
            case 6: insert_at_any_position();
                 break;
            case 7: delete_custom();
                break;
            case 8: printf("list contains %d nodes",count);
                break;
            case 9: search();
                break;
            case 10:replace_node();
                break;
            case 11:
                printf("Exited successfully\n"); 
                return 0;
            default: 
                printf("\n--Invalid choice--\n"); 
                break;
        }
    }
}
