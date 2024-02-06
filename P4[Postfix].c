#include<stdio.h>

void infix_to_postfix();
void push(char);
char pop();
int priopity(char);

char infix[30], postfix[30], stack[30];
int top=-1;

void main() {
	printf("Enter the valid infix expression : ");
	scanf("%s",infix);
	
	infix_to_postfix();
	
	printf("\nInfix Expression : %s",infix);
	printf("\nPostfix Expression : %s\n",postfix);
}

void push(char element) {
	stack[++top] = element;
}

char pop() {
	return stack[top--];
}

int priority(char op) {
	int value;
	switch(op) {
		case '+':
		case '-':
							value = 1;
							break;
		case '*':
		case '/':
		case '%':
							value = 2;
							break;
		case '$':
		case '^':
							value = 3;
							break;
		case '(':
		case ')':
							value = 0;
							break;
		case '#':
							value = -1;
							break;
	}
	return value;
}

void infix_to_postfix() {
	int i=0,j=0;
	char symb, temp;
	push('#');
	for(i=0 ; infix[i]!='\0' ; i++) {
		symb = infix[i];
		switch(symb) {
			case '(':
								push(symb);
								break;
			case ')':
								temp = pop();
								while(temp!='(') {
									postfix[j++] = temp;
									temp = pop();
								}
								break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '%':
			case '^':
			case '$': while(priority(stack[top])>priority(symb)) {
									temp = pop();
									postfix[j++] = temp;
								}
								push(symb);
								break;
			default: postfix[j++] = symb;
		}
	}
	while(top>0) {
		temp = pop();
		postfix[j++] = temp;
	}
	postfix[j] = '\0';
}
