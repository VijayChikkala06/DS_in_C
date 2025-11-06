#include<stdio.h>
#include<stdlib.h>
int count = 0;

struct node {
    int data;
    struct node *next;
};

struct node *head, *end;

void create_nodes() {
    int info;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Overflow\n");
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
void reverse() {
    struct node *prev = NULL, *next1 = NULL, *curr = head;

    if (head == NULL) {
        printf("\nList isn't created or is empty.\n");
        return;
    }

    end = head;  

    while (curr != NULL) {
        next1 = curr->next;  
        curr->next = prev;   
        prev = curr;         
        curr = next1;        
    }

    head = prev;  

    printf("\n----- List is reversed -----\n");
}
int main() {
    int ch;
    while(1) {
        printf("\n***CONTENTS***\n");
        printf("Select any number to get corresponding result:\n");
        printf("1. Create\n2. Display\n3.Reverse the list\n4.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &ch); 
        switch(ch) {
            case 1: create_nodes(); break;
            case 2: display(); break;
            case 3:reverse();break;
            case 4: printf("Exited successfully\n"); return 0;
            default: printf("\n--Invalid choice--\n"); break;
        }
    }
}
