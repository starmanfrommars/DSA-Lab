#include <stdio.h>
#include <stdlib.h>

#define MAX 4
int rear = -1, front=-1;
char queue[MAX];
char item;

void insert() {
	if(front==((rear+1)%MAX)) {
		printf("Circular Queue Overflow\n");
		return;
	}
	else {
		rear = (rear+1)%MAX;
		printf("Enter item : ");
		scanf("%*c%c",&item);
		queue[rear] = item;
		printf("Item inserted : %c\n",item);
		if(front==-1)
			front++;
	}
}

void del() {
	if(front==-1) {
		printf("Queue is Empty\n");
		return;
	}
	else {
		item = queue[front];
		printf("ITEM deleted : %c\n",item);
		if(front==rear)
			front=rear=-1;
		else
			front = (front+1)%MAX;
	}
}

void display() { 
	int i,j;
	if(front==-1) {
		printf("Queue is Empty\n");
		return;
	}
	else {
		printf("Elements of queue are : \n");
		i=front;
		while(i!=rear) {
			printf("%c",queue[i]);
			i = (i+1)%MAX;
		}
		printf("%c",queue[i]);
		printf("\n");
	}
}

void main() {
	int choice = 0;
	while(1) {
		printf("\nCircular Queue Operations\n");
		printf("1.Insert\t2.Delete\t3.Display\t4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: insert();
							break;
			case 2: del();
							break;
			case 3: display();
							break;
			case 4: exit(0);
							break;
			default: printf("Invalid Choice\n");
			return;
		}
	}		
}
