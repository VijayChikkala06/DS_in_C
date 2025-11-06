#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
void delete_begin();
void delete_end();
struct node *head = NULL, *end = NULL;
int count = 0;
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

void search()
{
	int key,list_count=0,found=0;
	struct node* curr=head;
	if (head == NULL) {
        printf("\nThe list is empty. Nothing to search.\n");
        return;
    }
    printf("\nEnter the key element you want to search:");
    scanf("%d",&key);
    while(curr!=NULL)
    {  list_count++;
    	if(curr->data==key)
    	{
    		printf("\nThe given Element = %d is found at position %d in the linked list\n",key,list_count);
    		found=1;
    		break;
		}
		curr=curr->next;
		if(curr==head && found==0) // To handle circular linked list and avoid infinite loop
		{
			break;
		}
	}
	if(found==0)
	{
		printf("\nElement not found in the linked list\n");
	}
}

void coustum_delete() {
	 if (head == NULL) {
        printf("The list is empty. Nothing to delete.\n");
        return;
    }
    int pos;
    struct node *tempo,*prev;
    printf("\nEnter the position you want to delete:");
    scanf("%d",&pos);
    if(pos<1||pos>count){
    	printf("Cannot delete at that position. Invalid position.\n");
    	return;
	}
    if (pos == 1) {
      delete_begin();
    }
    else if(pos==count){
    	delete_end();
	}
    else{
  	tempo=head;
  	 for(int i = 1; i < pos; i++) {
  	 	    prev=tempo;
            tempo = tempo->next;
        }
    prev->next=tempo->next;
    printf("\nDeleted node with data: %d\n", tempo->data);
    free(tempo);
    count--;
  }
}



void delete_end() {
    struct node *tempo=head;
    if (head == NULL) {
        printf("\nThe list is empty. No node to delete.\n");
        return;
    }

    if (head->next == head) { // Only one node in the list
        printf("\nDeleted node with data: %d\n", head->data);
        free(head);
        head = end = NULL;
        count--;
        return;
    }

    tempo = head;
    while (tempo->next != end) {
        tempo = tempo->next;
    }

    printf("\nDeleted node with data: %d\n", end->data);
    free(end);
    end = tempo;
    end->next = head; // Maintain the circular link
    count--;

    printf("\nLast element is deleted\n");
}

void delete_begin() {
    struct node *tempo;
    if (head == NULL) {
        printf("\nThe list is empty. No node to delete.\n");
        return;
    }

    tempo = head;
    if (head->next == head) {
        head = NULL;
        end = NULL;
    } else {
      head = head->next;
      end->next = head;
    }

    printf("\nDeleted node with data: %d\n", tempo->data);
    free(tempo);

    count--;
    printf("\nBeginning element is deleted\n");
}

void custom_insert() {
    int info, pos, i;
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory not allocated\n");
        return;
    }
     // Validate position
    if (pos < 1 || pos > count + 1) {
        printf("\nInvalid position\n");
        free(newnode);
        return;
    }

    
    printf("\nEnter the data into the node: ");
    scanf("%d", &info);
    newnode->data = info;

    printf("\nEnter the position: ");
    scanf("%d", &pos);
    
    // Case 1: Insert at the beginning
    if (pos == 1) {
        if (head == NULL) {
            head = end = newnode;
            newnode->next = head;
        } else {
            newnode->next = head;
            head = newnode;
            end->next = head;
        }
    }
    // Case 2: Insert at the end
    else if (pos == count + 1) {
        newnode->next = head;
        end->next = newnode;
        end = newnode;
    }
    // Case 3: Insert in the middle
    else {
        temp = head;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    count++;
    printf("\nNode inserted at position %d\n", pos);
}
void insert_end() {
    int info;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory isn't allocated\n");
        return;
    }
    printf("\nEnter data to the node: ");
    scanf("%d", &info);
    newnode->data = info;

    if (head == NULL) {
        head = end = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        end->next = newnode;
        end = newnode;
    }
    count++;
    printf("\nNew node is added at the end\n");
}


void insert_begin() {
    int info;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("\nMemory allocation failed\n");
        return;
    }

    printf("\nEnter data for the node: ");
    scanf("%d", &info);
    newnode->data = info;

    if (head == NULL) {
        head = end = newnode;
        newnode->next = head;
    } else {
        newnode->next = head;
        head = newnode;
        end->next = head;
    }

    count++;
    printf("\nNode inserted at the beginning.\n");
}



void create_node() {
    int info;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("OVERFLOW\n");
        return;
    }

    printf("\nEnter data for the node: ");
    scanf("%d", &info);
    newnode->data = info;

    if (head == NULL) {
        head = end = newnode;
        newnode->next = head;
    } else {
        end->next = newnode;
        newnode->next = head;
        end = newnode;
    }

    count++;
    printf("\nNode is created or added\n");
}


void display() {
    struct node *temp;

    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}


// Main function
int main() {
    int choice;
    do {
        printf("\n\n1. Create Node");
        printf("\n2. Display List");
        printf("\n3. Add Element at the Beginning");
        printf("\n4. Add Element at the End");
        printf("\n5. Adding element in custom position");
        printf("\n6. Delete Element from the Beginning");
		printf("\n7. Delete Element from the end");
		printf("\n8. Delete Element in custom position");
		printf("\n9. Search an element in the linked list");
		printf("\n10. Replace Data in a Node");
		printf("\n11. Exit");
        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 1:create_node(); break;
            case 2:display(); break;
            case 3:insert_begin(); break;
            case 4:insert_end(); break;
            case 5:	custom_insert();break;
            case 6: delete_begin();	break;
            case 7:	delete_end();break;
            case 8:coustum_delete();break;
            case 9: search();break;
			case 10: replace_node();break;
            case 11: printf("\nExited successfully\n");	break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 11);

    return 0;
}