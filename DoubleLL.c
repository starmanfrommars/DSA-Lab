#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* llink;
	struct node* rlink;
};

typedef struct node* NODE;
NODE first = NULL;

NODE getnode() {
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	return x;
}

NODE create() {
	NODE temp;
	temp = getnode();
	printf("Enter usn : ");
	scanf("%s",temp->data);
	temp->link=NULL;
	return temp;
}

void insertfront() {
	NODE temp;
	temp = create();
	if(first==NULL) {
		first = temp;
		return;
	}
	else {
		temp->rlink = first;
		first->llink = temp;
		first=temp;
	}
}

void deletefront() {
	NOde temp;
	if(first==NULL)
		printf("List is empty\n");
	else if(first->llink==NULL) {
		free(first);
		first = NULL;
	}
	else {
		temp = first;
		first = temp->llink;
		temp->rlink = NULL;
		first->llink = NULL;
		free(temp);
		temp = NULL;
	}
}

void insertend() {
	NODE temp, cur;
	temp = create();
	if(first==NULL) 
		first = temp;
	else {
		cur = first;
		while(cur->rlink!=NULL)
			cur = cur->rlink;
		cur->rlink = temp;
		temp->llink = cur;
	}
}

void deleteend() {
	NODE cur;
	if(first==NULL)
		printf("List is empty\n");
	else if(first->rlink==NULL) {
		free(first);
		first=NULL;
	}
	else {
		cur = first;
		while(cur-rlink!=NULL)
			cur = cur->rlink;
		cur-llink->rlink = NULL;
		cur->llink = NULL;
		free(cur);
		cur = NULL;
	}
}

void display() {
	
}

void main() {

}
