#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

typedef struct BST{
	int data;
	struct BST *lchild,*rchild;
}node;

node * getnode();
void insert(node *, node *);
void inorder(node *);
void preorder(node *);
void postorder(node *);
node * search(node *, int, node **);

int main()
{
	char c;
	int key;
	node *root,*new_node,*search_ptr,*parent;
	root=NULL;
	while(1)
	{
		p("\n\n=====================[Program on Binary Search Tree]=====================");
		p("\n1.Insert.\n2.Recursive Traversal.\n3.Search.\n4.Exit.\nEnter your choice: ");
		//s(" %c",&c);
		c = getch();
		switch(c)
		{
			case '1':
				new_node = getnode();
				p("\nEnter the value: ");
				s("%d",&new_node->data);
				if(root==NULL)	root = new_node;
				else insert(root,new_node);
				p("\n\nTree in Inorder:\n");
				inorder(root);
				break;
			
			case '2':
				system("cls");
				p("\n\nTree in Preorder:\n");
				preorder(root);
				p("\n\nTree in Inorder:\n");
				inorder(root);
				p("\n\nTree in Postorder:\n");
				postorder(root);
				break;
			
			case '3':
				p("\nEnter the value to be searched: ");
				s("%d",&key);
				search_ptr = search(root,key,&parent);
				if(search_ptr == NULL){
					p("\nValue Not Found!");
					break;
				}
				if(parent == NULL)	p("\n%d is the root",search_ptr->data);
				else p("\nParent of Node %d is %d ",search_ptr->data,parent->data);
				break;
			case '4':
				return 0;
			
			default:
				p("\nInvalid Choice!");
	 	}
	}
	return 0;
}

node * getnode()
{
	node *temp = malloc(sizeof(node));
	temp->lchild = NULL;
	temp->rchild = NULL;
	return temp;
}

void insert(node *root, node *new_node)
{
	if(new_node->data < root->data)
	{
		if(root->lchild == NULL)	root->lchild = new_node;
		else insert(root->lchild,new_node);
	}
	
	if(new_node->data > root->data)
	{
		if(root->rchild == NULL)	root->rchild = new_node;
		else insert(root->rchild,new_node);
	}
}

void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		p("%d ",temp->data);
		inorder(temp->rchild);
	}
}

void preorder(node *temp)
{
	if(temp!=NULL)
	{
		p("%d ",temp->data);
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);
		postorder(temp->rchild);
		p("%d ",temp->data);
	}
}

node * search(node *temp, int key, node **parent)
{
	*parent = NULL;
	while(temp!=NULL){
		if(temp->data == key){
			p("\nThe Value %d is Present",temp->data);
			return temp;
		}
		*parent = temp;
		if(temp->data > key)	temp = temp->lchild;
		else temp = temp->rchild;
	}
	return NULL;
}
