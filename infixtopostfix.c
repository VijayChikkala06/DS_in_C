#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 30
int top=-1;
int stack[SIZE];
int precedence(char);
void push(char); 
char pop();
char peek();
void infix_to_postfix(char*);

int precedence(char ch){
	switch(ch){
		case '+':
		case '-':return 1;
		case '*':
		case '/':
		case '%':return 2;
		case '^':return 3;
		default: return 0;
	}
}

void push(char ch){
	top++;
	stack[top]=ch;
}

char pop(){
	return stack[top--];
}

char peek(){
	return stack[top];
}

void infix_to_postfix(char *ex){
	char postfix[SIZE];
	int n=strlen(ex),i,j=0;
	for(i=0;i<n;i++){
		if(ex[i]=='('||ex[i]==')'||isalnum(ex[i])||ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^'){
			if(isalnum(ex[i]))
			postfix[j++]=ex[i];
			else if(ex[i]=='(')
			push(ex[i]);
			else if(ex[i]==')'){
				while(top!=-1&&peek()!='(')
				postfix[j++]=pop();
				if(top==-1){
					printf("Invalid expression: Unmatched parenthesis1\n");
					exit(1);
				}
				pop();
			}
			else{
				while(top!=-1&&precedence(peek())>=precedence(ex[i])){
					postfix[j++]=pop();
				}
				push(ex[i]);
			}
		}//end of main if
			else{
				printf("Invalid expression: Invalid character '%c'\n", ex[i]);
				exit(1);
			}
		}//end of for
		while(top!=-1){
			char ch= pop();
			if(ch=='('){
				printf("Invalid expression: Unmatched parenthesis2\n");
				exit(1);
			}
			postfix[j++]=ch;
		}
		postfix[j]='\0';
		printf("Postfix expression is %s\n",postfix);
}
int main(){
	char expression[SIZE];
	printf("Enter a valid expression: ");
    scanf("%[^\n]%*c", expression);
	infix_to_postfix(expression);
	return 0;
}