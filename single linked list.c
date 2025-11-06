 #include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head=NULL, *end=NULL;

int count = 0;

void create_nodes() {
    int info;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("memory can't allocate:\n");
        return;
    }   
    printf("Enter data into a node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;
    
    if(head == NULL){
        head = end = newnode;
    }
    else {
        end->next = newnode;
        end = newnode;
    }
    count++;
    printf("Node is Created\n");
}

void display() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while(temp != NULL) {
        if(temp->next == NULL)
            printf("%d", temp->data);
        else	
            printf("%d -> ", temp->data); 
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_beg() {
    int info;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory not created\n");
        return;
    }
    printf("Enter data into a node: ");
    scanf("%d", &info);
   	newnode->data = info;
    if(head==NULL){
    	newnode->next=NULL;
    	head=end=newnode;
	}
	else{
   newnode->next = head;
    head = newnode;
  }
    count++;
    printf("Node is added\n");
}

void insert_at_end() {
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory not created\n");
        return;
    }
    printf("Enter data into a node: ");
    scanf("%d", &info);
   	newnode->data = info;
    if(head==NULL){
    newnode->next = NULL;
    head=end=newnode;
 }
 else{
    end->next = newnode;  
    end = newnode;  
	}      
    count++;
    printf("Node is added\n");
}

void insert_at_any_pos() {
    int info, pos, i;
    struct node *newnode, *temp;
    printf("Enter the position you want to insert: ");
    scanf("%d", &pos);
    
    if(pos < 1 || pos > count+1)
    {
        printf("Can't insert at this position.\n");
        return;
    }
    
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory not created\n");
        return;
    }
    
    printf("Enter data into a node: ");
    scanf("%d", &info);
    newnode->data = info;
    newnode->next = NULL;
    
    if(pos == 1) {
        newnode->next = head;
        head = newnode;
    } 
	else if(pos==count+1){
    end->next = newnode;  
    end = newnode;    
    }
    else{
    temp = head;
        for(i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    count++;
    printf("Node is added\n");
}
}

void delete_at_beg() {
    struct node *tempo;
    if(head == NULL) {
        printf("\nThe list is empty. No node to delete.\n");
        return;
    }
    tempo = head;
     if(head->next == NULL) {
        printf("\nDeleted node with data: %d\n", head->data);
        free(tempo);
        head = end = NULL;
    }
    else{
    head = head->next;
    printf("\nDeleted node with data: %d\n", tempo->data);
    free(tempo);
}
    count--;
}

void delete_at_end() {
    struct node *tempo, *prev;
    if(head == NULL) {
        printf("\nThe list is empty. No node to delete.\n");
        return;
    }
    tempo = head;
    if(head->next == NULL) {
        printf("\nDeleted node with data: %d\n", head->data);
        free(tempo);
        head = end = NULL;
    } else {
        while(tempo->next != NULL) {
            prev = tempo;
            tempo = tempo->next;
        }
        prev->next = NULL;
        printf("\nDeleted node with data: %d\n", tempo->data);
        free(tempo);
        end = prev;
    }
    count--;
}

void delete_at_any_pos() {
    int pos;
    struct node *tempo = head,*prev;
     if(head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Enter the position you want to delete: ");
    scanf("%d", &pos);
       if(pos < 1 || pos > count)
    {
        printf("Can't delete at this position.\n");
        return;
    }
    if(pos == 1)
    delete_at_beg() ;   
    else if(pos==count)
    delete_at_end();
  else{
  	tempo=head;
  	 for(int i = 1; i < pos; i++) {
  	 	    prev=tempo;
            tempo = tempo->next;
        }
    prev->next=tempo->next;
    printf("\nDeleted node with data: %d\n", tempo->data);
    free(tempo); 
  }
}

void search() {
    int key, pos = 1, found = 0;
    struct node *curr = head;
    
    if(head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    
    printf("Enter the key element you wanna search: ");
    scanf("%d", &key);
    
    while(curr != NULL) {
        if(curr->data == key) {
            printf("\nThe given element %d is found at position %d in the linked list.\n", key, pos);
            found = 1;
            break;
        }
        curr = curr->next;
        pos++;
    }
    
    if(!found) {
        printf("\nElement not found in the linked list.\n");
    }
}

int main() {
    int ch;
    while(1) {
        printf("\n***CONTENTS***\n");
        printf("Select any number to get corresponding result:\n");
        printf("1. Create\n2. Display\n3. Size of List\n4. Insert at beginning\n5.Insert at end\n6. Insert at any position\n7. Delete at beginning\n8.Delete at end\n9. Delete at any position\n10. Search\n11. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch); 
        switch(ch) {
            case 1: create_nodes(); break;
            case 2: display(); break;
            case 3: printf("\nNo. of Nodes: %d\n", count); break;
            case 4: insert_at_beg(); break;
            case 5: insert_at_end(); break;
            case 6: insert_at_any_pos(); break;
            case 7: delete_at_beg(); break;
            case 8: delete_at_end(); break;
            case 9: delete_at_any_pos(); break;
            case 10: search(); break;
            case 11: printf("Exited successfully\n"); return 0;
            default: printf("\n--Invalid choice--\n"); break;
        }
    }
    return 0;
}
