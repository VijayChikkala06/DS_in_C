#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
# define SIZE 20
int top=-1;
int stack[SIZE];
void push(int);
int pop();
int peek();
int evaluation_of_postfix(char *ex);

void push(int n ){
	top++;
	stack[top]=n;
}

int pop(){
	return stack[top--];
}

int evaluation_of_postfix(char *ex){
	int operand_count=0, operator_count=0, i;
	for(i=0; ex[i]!='\0'; i++){
	 if(isdigit(ex[i]))
	 operand_count++;
	 else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^'){
			operator_count++;
	}
	}
	if(operand_count <= operator_count){
		printf("Invalid expression: Insufficient operands\n");
		exit(0);
	}
	for(i=0; ex[i]!='\0'; i++){
		if(isdigit(ex[i])){
			push(ex[i]-'0');
		}
		else if(ex[i]=='+'||ex[i]=='-'||ex[i]=='*'||ex[i]=='/'||ex[i]=='%'||ex[i]=='^'){
			int x1,x2;
			x1=pop();
			x2=pop();
			switch(ex[i]){
				case '+':push(x2+x1);break;
				case '-':push(x2-x1);break;
				case '*':push(x2*x1);break;
				case '/':push(x2/x1);break;
				case '%':push(x2%x1);break;
				case '^':push(pow(x2,x1));break;
			    }
			}
		else{
			printf("Invalid expression: Invalid character '%c'\n", ex[i]);
			exit(0);
		}
	}
	if(top!=0){
		printf("Invalid expression: Too many operands\n");
		exit(0);
	}
	else {
		return stack[top];
	}
}

int main(){
	char expression[SIZE];
	int result;
	printf("Enter a valid postfix expression: ");
   scanf("%[^\n]%*c", expression);
	result= evaluation_of_postfix(expression);
	printf("The result of the postfix expression is: %d\n", result);
	return 0;
}