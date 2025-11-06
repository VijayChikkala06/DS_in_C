#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    struct node *left;
    int data;
    struct node *right;
};

typedef struct node NODE;
NODE *root = NULL;

// Function declarations
void create(int);
void insert(NODE*, NODE*);

void traverse(NODE*);

// Function to create and insert a new node
void create(int value) {
    NODE *newnode = (NODE*)malloc(sizeof(NODE));
    if (newnode == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    newnode->data = value;
    newnode->left = newnode->right = NULL;

    if (root == NULL)
        root = newnode; // First node becomes root
    else
        insert(root, newnode); // Insert elsewhere
}

// Recursive insertion
void insert(NODE *root, NODE *newnode) {
    if (newnode->data < root->data) {
        if (root->left == NULL)
            root->left = newnode;
        else
            insert(root->left, newnode);
    } else {
        if (root->right == NULL)
            root->right = newnode;
        else
            insert(root->right, newnode);
    }
}
// In-order traversal of the BST
void traverse(NODE *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        traverse(root->left);
        traverse(root->right);
    }
}

void post_order_traverse(NODE *root) {
    if (root != NULL) {
        traverse(root->left);
        traverse(root->right);
        printf("%d\t", root->data);
    }
}
// Main menu
int main() {
    int ch, value;
    do {
        printf("1. Insert\n2.Traverse (pre-Order)\n3.Traverse (post-Order)\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                create(value);
                break;
            case 2:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Pre-Order Traversal: ");
                    traverse(root);
                    printf("\n");
                }
                break;
            	case 3:
                if (root == NULL)
                    printf("Tree is empty\n");
                else {
                    printf("Post-Order Traversal: ");
                    post_order_traverse(root);
                    printf("\n");
                }
                break;
                case 4:
                	exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (1);
}