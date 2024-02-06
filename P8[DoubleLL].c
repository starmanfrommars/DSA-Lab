#include<stdio.h>
#include<stdlib.h>

struct node {
	int snn;
	float sal;
	char name[20], dept[10], desg[20], phno[15];
	struct node* llink;
	struct node* rlink;
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
	printf("Enter the employee details : \n");
	printf("Enter SSN : ");
	scanf("%d",&temp->snn);
	printf("Enter Name : ");
	scanf("%s",temp->name);
	printf("Enter Department : ");
	scanf("%s",temp->dept);
	printf("Enter Designation : ");
	scanf("%s",temp->desg);
	printf("Enter Salary : ");
	scanf("%f",&temp->sal);
	printf("Enter Phone No : ");
	scanf("%s",temp->phno);
	temp->llink = NULL;
	temp->rlink = NULL;
	count++;
	return temp;
}

void disp_deleted(NODE temp) {
	printf("The following semployee details is deleted : \n");
	printf("SSN|Name|Dept|Designation|Salary|Ph No\n");
	printf("%d|%s|%s|%s|%.2f|%s\n",temp->snn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
	count--;
}

void insert_front() {
	NODE temp;
	temp = create();
	if(first==NULL)
		first = temp;
	else {
		temp->rlink = first;
		first->llink = temp;
		first=temp;
	}
}

void delete_front() {
	NODE temp;
	if(first==NULL) {
		printf("List is empty\n");
	}
	else if(first->rlink==NULL) {
		disp_deleted(first);
		free(first);
		first = NULL;
	}
	else {
		temp = first;
		disp_deleted(first);
		first = first->rlink;
		first->llink = NULL;
		temp->rlink = NULL;
		free(temp);
		temp=NULL;
	}
}

void insert_rear() {
	NODE temp, cur;
	temp = create();
	if(first==NULL) {
		first = temp;
	}
	else {
		cur = first;
		while(cur->rlink!=NULL) 
			cur = cur->rlink;
		cur->rlink = temp;
		temp->llink = cur;
	}
}

void delete_rear() {
	NODE cur;
	if(first==NULL) {
		printf("List is empty.\n");
	}
	else if(first->rlink==NULL) {
		disp_deleted(first);
		free(first);
		first=NULL;
	}
	else {
		cur=first;
		while(cur->rlink!=NULL) {
			cur = cur->rlink;
		}
		disp_deleted(cur);
		cur->llink->rlink = NULL;
		cur->llink = NULL;
		free(cur);
		cur = NULL;
	}
}

void display() {
	NODE temp;
	if(first==NULL) {
		printf("LIST is empty\n");
	}
	else {
		printf("The employee details in Double Linked List from beginning : \n");
		printf("SSN|Name|Dept|Designation|Salary|Ph No\n");
		printf("------------------------------------------------\n");
		temp = first;
		while(temp!=NULL) {
			printf("%d|%s|%s|%s|%.2f|%s\n",temp->snn,temp->name,temp->dept,temp->desg,temp->sal,temp->phno);
			temp = temp->rlink;
		}
		printf("No of Employees = %d\n",count);
	}
}

void main() {
	int choice,n,i;
	while(1) {
		choice = 0;
		printf("--------------------MENU--------------------\n");
		printf("1.Create a DLL of N Employees using End Insertion\n");
		printf("2.Display Status and Counbt of nodes\n");
		printf("3.Insertion at Rear\n");
		printf("4.Deleteion at Rear\n");
		printf("5.Insertion at Front\n");
		printf("6.Deleteion at Front\n");
		printf("7.Exit\n");
		printf("--------------------------------------------\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: printf("Enter no of employees : ");
							scanf("%d",&n);
							for(i=0;i<n;i++)
								insert_rear();
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
