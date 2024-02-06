#include<stdio.h>
#include<stdlib.h>

struct node {
	int coef;
	int expox;
	int expoy;
	int expoz;
	struct node* link;
};

typedef struct node* NODE;

NODE createnode(int coef,int ex,int ey,int ez) {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->coef = coef;
	temp->expox = ex;
	temp->expoy = ey;
	temp->expoz = ez;
	temp->link  = NULL;
	return temp;
}

NODE createheadnode() {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->coef = 0;
	temp->expox = -1;
	temp->expoy = -1;
	temp->expoz = -1;
	temp->link = temp;
	return temp;
}

NODE createpoly(NODE poly) {
	int i,n;
	int coef,ex,ey,ez;
	printf("Enter the number of terms : ");
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		printf("Enter the coefficient : ");
		scanf("%d",&coef);
		printf("Enter the exponent of (x,y,z) :");
		scanf("%d%d%d",&ex,&ey,&ez);
		poly = insert_rear(corf,ex,ey,ez,poly);
	}
	return poly;
}

NODE insert_rear(int coef,int ex,int ey,int ez,head) {  //**
	NODE temp,cur;
	temp = createnode(coef,ex,ey,ez);
	if(head->link==head)
		head->link = temp;
	else {
		cur = head;
		while(cur-<>link!=head)
			cur = cur->link;
		cur->link = head;
	}
	head->coef = (head->coef) + 1;
	return head;
}
		
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
