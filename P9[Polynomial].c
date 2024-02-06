#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

NODE insert_rear(int coef,int ex,int ey,int ez,NODE head) {  
	NODE temp,cur;
	temp = createnode(coef,ex,ey,ez);
	if(head->link==head)
		head->link = temp;
	else {
		cur = head;
		while(cur->link!=head)
			cur = cur->link;
		cur->link = temp;
	}
	temp->link = head;
	head->coef = (head->coef) + 1;
	return head;
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
		poly = insert_rear(coef,ex,ey,ez,poly);
	}
	return poly;
}

void display(NODE head) {
	NODE cur;
	if(head->link == head)
		printf("List is empty\n");
	else {
		cur = head->link;
		while(cur != head) {
			if(cur->coef < 0)
				printf(" %dx^%dy^%dz^%d ",cur->coef,cur->expox,cur->expoy,cur->expoz);
			else
				printf(" +%dx^%dy^%dz^%d ",cur->coef,cur->expox,cur->expoy,cur->expoz);
			cur = cur->link;
		}
		printf("\nNumber of terms = %d",head->coef);
	}
}

double evaluate(int x,int y,int z,NODE head) {
	double result = 0;
	NODE cur;
	if(head->link == head)
		printf("List is empty\n");
	else {
		cur = head->link;
		while(cur != head) {
			result += cur->coef * pow(x,cur->expox) * pow(y,cur->expoy) * pow(z,cur->expoz);
			cur = cur->link;
		}
	}
	return result;
}

NODE polyadd(NODE a,NODE b) {
	NODE c, starta, startb;
	int sum = 0;
	starta = a;
	startb = b;
	a = a->link;
	b = b->link;
	c = createheadnode();
	while((a!=starta) && (b!=startb)) {
		if((a->expox == b->expox) && (a->expoy == b->expoy) && (a->expoz == b->expoz)) {
			sum = (a->coef) + (b->coef);
			c = insert_rear(sum,a->expox,a->expoy,a->expoz,c);
			a = a->link;
			b = b->link;
		}
		else if(a->expox > b->expox) {
			c = insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
			a = a->link;
		}
		else if((a->expox == b->expox) && (a->expoy > b->expoy)) {
			c = insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
			a = a->link;
		}
		else if((a->expox == b->expox) && (a->expoy == b->expoy) && (a->expoz > b->expoz)) {
			c = insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
			a = a->link;
		}
		else {
			c = insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
			b = b->link;
		}
	}
	
	while(a!=starta) {
		c = insert_rear(a->coef,a->expox,a->expoy,a->expoz,c);
		a = a->link;
	}
	while(b!=startb) {
		c = insert_rear(b->coef,b->expox,b->expoy,b->expoz,c);
		b = b->link;
	}
	return c;
}
		
void main() {
	int x,y,z;
	double eval = 0;
	NODE poly1 = NULL;
	NODE poly2 = NULL;
	NODE polysum = NULL;
	
	printf("********Evaluation of a Polynomial********\n"); 
	poly1 = createheadnode();
	poly1 = createpoly(poly1);
	printf("Polynamial is : \n");
	display(poly1);
	printf("\nEnter the values for x,y and z : ");
	scanf("%d%d%d",&x,&y,&z);
	eval = evaluate(x,y,z,poly1);
	printf("Polynomial Evaluation Value = %0.2f\n",eval);
	
	
	printf("********Addition of two Polynomials********\n");
	poly1 = NULL;
	poly1 = createheadnode();
	poly1 = createpoly(poly1);
	poly2 = createheadnode();
	poly2 = createpoly(poly2);
	
	printf("Polynomial 1 is : \n");
	display(poly1);
	printf("\nPolynomial 2 is : \n");
	display(poly2);
	polysum = polyadd(poly1,poly2);
	printf("\nPolynomial sum is : \n");
	display(polysum);
	printf("\n");
}
	 
		
		
		
		
		
		
		
		
		
		
		
		
