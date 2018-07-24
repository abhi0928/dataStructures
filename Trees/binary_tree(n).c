#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

typedef struct node{
	int data;
	struct node *left,*right;
}node;

node *temp;
int flag;
void insert(node **root)
{
	if(*root == NULL)	*root = temp;
	else if((*root)->data > temp->data)	insert(&((*root)->left));
	else	if((*root)->data < temp->data)	insert(&((*root)->right));
}

void new_node(node **root)
{
	temp = (node *)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	p("Enter the value you want to insert: ");
	s("%d",&temp->data);
	insert(&(*root));
}

void preorder(node *root)
{
	if(root != NULL){
		p("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root)
{
	if(root != NULL){
		inorder(root->left);
		p("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(node *root)
{
	if(root != NULL){
		postorder(root->left);
		postorder(root->right);
		p("%d ",root->data);
	}
}

node * search(node *temp,node **parent)
{
	int key;
	p("Enter the value you want to search: ");
	s("%d",&key);
	*parent = NULL;
	while(temp!=NULL){
		if(temp->data == key)	return temp;
		*parent = temp;
		if(temp->data > key)	temp = temp->left;
		else if(temp->data < key)	temp = temp->right;
	}
	return NULL;
}


int main()
{
	
	node *root = NULL,*parent;
	int key;
	char c;
	while(1)
	{
		p("\n\n***********************Binary Tree***********************");
		p("\n\n1.Insert.\n2.Display.\n3.Search.\n4.Clear Screen.\n5.Exit.\nEnter your choice: ");
		s(" %c",&c);
		switch(c)
		{
			case '1':
				new_node(&root);
				break;
			
			case '2':
				if(root != NULL)
{
					p("\n\nPreorder:\n");
					preorder(root);
					p("\n\nInorder:\n");
					inorder(root);
					p("\n\nPostorder:\n");
					postorder(root);
				}
				else	p("\n\nTree Not Created!\n");
				break;
			
			case '3':
				if(root != NULL){
					node *ptr = search(root,&parent);
					if (ptr == NULL)	p("\n\nValue Not Found!");
					else if(parent == NULL)	p("\n\nValue present! Node Value %d is the root!",ptr->data);
					else p("\n\nNode Value %d is present! Its Root Node Value is %d",ptr->data,parent->data);
				}
				else p("\n\nTree not Created!");
				break;
			
			case '4':
				system("clear");
				//system("cls");
				break;
			
			case '5':
				return 0;
				
			default:
				p("\n\nWrong Choice!");
		}
	}
	return 0;
}
