#include<stdio.h>
#include<stdlib.h>
int flag,i;

// 6 9 5 2 8 15 24 14 7 4

struct node {
	int data;
	struct node *leftchild, *rightchild;
};
typedef struct node *NODE;

NODE createnode(int item) {
	NODE temp;
	temp = (NODE)malloc(sizeof(struct node));
	temp->data = item;
	temp->leftchild = NULL;
	temp->rightchild = NULL;
	return temp;
}
void insertBST(NODE root, NODE newnode) {
	if(newnode->data==root->data) {
		printf("Key already exists\n");
		i--;
		return;
	}
	else if(newnode->data < root->data) {
		if(root->leftchild == NULL)
			root->leftchild = newnode;
		else
			insertBST(root->leftchild, newnode);
	}
	else {
		if(root->rightchild == NULL)
			root->rightchild = newnode;
		else
			insertBST(root->rightchild, newnode);
	}
}
		
int search(NODE root, int key) {
	if(!root)
		return -1;
	if(key==root->data)
		return 1;
	if(root->data > key)
		return search(root->leftchild, key);
	else
		return search(root->rightchild, key);
}

void inorder(NODE temp) {
	if(temp!=NULL) {
		inorder(temp->leftchild);
		printf("%d\t",temp->data);
		inorder(temp->rightchild);
	}
}

void preorder(NODE temp) {
	if(temp!=NULL) {
		printf("%d\t",temp->data);
		preorder(temp->leftchild);
		preorder(temp->rightchild);
	}
}

void postorder(NODE temp) {
	if(temp!=NULL) {
		postorder(temp->leftchild);
		postorder(temp->rightchild);
		printf("%d\t",temp->data);
	}
}

void main() {
	int choice,n,item;
	int key, keyfound=0;
	NODE root=NULL, newnode;
	
	while(1) {
		choice=0;
		printf("\n----------MENU----------\n");
		printf("1. Create a BST\n");
		printf("2. Traverse a BST\n");
		printf("3. Search a BST\n");
		printf("4. Exit\n");
		printf("--------------------------\n");
		printf("Enter choice : ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1: root = NULL;
							printf("Enter the number of elements in BST : ");
							scanf("%d",&n);
							for(i=0;i<n;i++) {
								printf("Enter the integer : ");
								scanf("%d",&item);
								newnode = createnode(item);
								
								if(root==NULL)
									root = newnode;
								else
									insertBST(root, newnode);
							}
							break;
			case 2: if(root==NULL){
								printf("Tree is empty\n");
								break;
							}
							else {
								printf("BST Preorder Traversal\n");
								preorder(root);
								
								printf("\3nBST Inorder Traversal\n");
								inorder(root);
								
								printf("\nBST Postorder Traversal\n");
								postorder(root);
								break;
							}			
			case 3: printf("Enter the search key : ");
							scanf("%d",&key);
							keyfound = search(root,key);
							if(keyfound==1)
								printf("Element %d is found in BST",key);
							else 		
								printf("Element %d is not found in BST",key);
							break;
			case 4: return;
			default: printf("Wrong Choice\n");
							 return;
		}
	}
}
