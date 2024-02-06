#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int top = -1;
int stack[MAX],element,i;

void push() {
	if(top==MAX-1) {
		printf("Stack overflow\n");
		exit(0);
	}
	else {
		printf("Enter the element to be inserted : ");
		scanf("%d",&element);
		stack[++top] = element;
	}
}

void pop() {
	if(top==-1) {
		printf("Stack underflow\n");
		exit(0);
	}
	else {
		element = stack[top--];
		printf("Element %d was popped",element);
	}
}

void display() {
	printf("The elements of the stack are : \n");
	for( i=top ; i>-1 ; i-- ) {
		printf("%d ",stack[i]);
	}
}

void palindrome() {
	int count=0;
	
	for(i=0;i<=top/2;i++) {
		if(stack[i]==stack[top-i]) {
			count++;
		}
	}
	if(count==((top/2)+1)) {
		printf("Palindrome found\n");
	}
	else {
		printf("No palindrome\n");
	}
}

void main () {
	int choice;
	
	while(1) {
		printf("\n1.Push 2.Pop 3.Display 4.Palindrome 5.Exit\nEnter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: push();
							break;
			case 2: pop();
							break;
			case 3: display();
							break;
			case 4: palindrome();
							break;
			case 5: exit(0);
			
			default: printf("Invalid Choice"); 
		}
	}
}
