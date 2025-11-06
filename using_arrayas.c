#include <stdio.h>
#include <stdlib.h>

#define size 7
int stack[size], top = -1;
void push(int);
int pop();
int peek();
void display();

void push(int n)
{
    if (top == size - 1)
    {
        printf("\nStack is Overflow");
    }
    else
    {
        top = top + 1;
        stack[top] = n;
    }
    printf("Element is inserted\n");
}

int pop()
{
    int x;
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return 0; // Or consider returning -1 for error
    }
    else
    {
        x = stack[top];
        top--;
        return x;
    }
}

int peek()
{
    if (top == -1)
    {
        printf("Stack is Empty\n");
        return 0; // Or consider returning -1 for error
    }
    else
    {
        return stack[top];
    }
}

void display()
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (i = top; i >= 0; i--)
        {
            printf("\t%d\n", stack[i]);
        }
    }
}

int main()
{
    int ch, x;
    while(1)
    {
        printf("\n1.push\n2.pop\n3.peek\n4.display\n5.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element: ");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            x = pop();
            if (x != 0)
                printf("popped element is %d\n", x);
            break;
        case 3:
            x = peek();
            if (x != 0) 
                printf("the top most element is %d\n", x);
            break;
        case 4:
            display();
            break;
        case 5:
            printf("exited successfully!");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}