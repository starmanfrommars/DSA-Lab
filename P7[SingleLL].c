#include<stdio.h>
#include<stdlib.h>

struct node {
	int sem;
	char name[20], programme[10], usn[20], phno[15];
	struct node* link;
};

typedef struct node* NODE;
NODE first = NULL;
int count = 0;
NODE getnode() {
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	return x;
}

NODE create() {
	NODE temp;
	temp = getnode();
	printf("Enter the student details : \n");
	printf("Enter usn : ");
	scanf("%s",temp->usn);
	printf("Enter name : ");
	scanf("%s",temp->name);
	printf("Enter programme : ");
	scanf("%s",temp->programme);
	printf("Enter sem : ");
	scanf("%d",&temp->sem);
	printf("Enter phone no : ");
	scanf("%s",temp->phno);
	temp->link = NULL;
	count++;
	return temp;
}

void disp_deleted(NODE temp) {
	printf("The following student details is deleted : \n");
	printf("|USN|Name|Programme|Sem|Phone|\n");
	printf("|%s|%s|%s|%d|%s|\n",temp->usn,temp->name,temp->programme,temp->sem,temp->phno);
	count--;
}

void insert_front() {
	NODE temp;
	temp = create();
	temp->link = first;
	first=temp;
}

void delete_front() {
	NODE temp;
	if(first==NULL) {
		printf("List is empty. Cannopt delete\n");
		return;
	}
	temp = first;
	first = first->link;
	disp_deleted(temp);
	temp->link = NULL;
	free(temp);
	temp=NULL;
}

void insert_rear() {
	NODE temp, cur;
	temp = create();
	if(first==NULL) {
		first = temp;
		return;
	}
	cur = first;
	while(cur->link!=NULL) 
		cur = cur->link;
	cur->link = temp;
}

void delete_rear() {
	NODE cur,prev;
	if(first==NULL) {
		printf("List is empty. Cannopt delete\n");
		return;
	}
	if(first->link==NULL) {
		disp_deleted(first);
		free(first);
		first=NULL;
		return;
	}
	prev=NULL;
	cur=first;
	while(cur->link!=NULL) {
		prev = cur;
		cur = cur->link;
	}
	disp_deleted(cur);
	prev->link = NULL;
	free(cur);
	cur = NULL;
}

void display() {
	NODE temp;
	if(first==NULL) {
		printf("LIST is empty\n");
		return;
	}
	printf("The student details in Single Linked List from beginning : \n");
	printf("|USN|Name|Programme|Sem|Phone|\n");
	printf("------------------------------------------------\n");
	temp = first;
	while(temp!=NULL) {
		printf("|%s|%s|%s|%d|%s|\n",temp->usn,temp->name,temp->programme,temp->sem,temp->phno);
		temp = temp->link;
	}
	printf("No of students = %d\n",count);
}

void main() {
	int choice,n,i;
	while(1) {
		choice = 0;
		printf("--------------------MENU--------------------\n");
		printf("1. Create a SLL of N students using front insertion\n");
		printf("2.Display from beginning\n");
		printf("3.Insert at End\n");
		printf("4.Delete at End\n");
		printf("5.Insert at Beginning\n");
		printf("6.Delete at Beginning\n");
		printf("7.Exit\n");
		printf("--------------------------------------------\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: printf("Enter no of students : ");
							scanf("%d",&n);
							for(i=0;i<n;i++)
								insert_front();
							break;
			case 2: display();
							break;
			case 3: insert_rear();
							break;
			case 4: delete_rear();
							break;
			case 5: insert_front();
							break;
			case 6: delete_front();
							break;
			case 7: exit(0);
			default: printf("Invalid Choice\n");
							break;
		}
	}
}
