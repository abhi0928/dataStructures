#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

struct node{				//definition of structure to implement linked list
	int data;
	struct node *next;
}*start,*ptr,*newptr;

struct node * create_node(int d);		//function to create a node and and enter data into it

void insert_fron(struct node *np);		//function to link two nodes

void display(struct node *np);			//function to display elements of the list

void delete_front(struct node *np);		//function to delete elements of the list

int main()
{
	int value;
	char choice,ans;
	
	start=NULL;							//at first start pointer points to NULL
	while(1)
	{
		p("\n\nOperations on Stack using Linked List:\n");
		p("\n1.Push elements.\n2.Pop elements.\n3.Display elements.\n4.Exit\n5.Clear Screen\n\nEnter your choice[1-5]: ");
		s(" %c", &choice);
		switch(choice)
		{
			case '1':
				//system("tput clear");
				do
				{
					p("\nEnter a value: ");
					s("%d",&value);
					newptr = create_node(value);
					insert_fron(newptr);
					p("\nThe list is:\n");
					display(start);
					p("\n\nDo you want to insert another element(y/n) ");
					s(" %c",&ans);
				}while(ans=='Y'||ans=='y');
				break;
				
			case '2':
				if(start==NULL){
					system("tput clear");
					p("\nNo elements to delete! Empty List!");
				}
				else
				do
				{
					if(start==NULL){
					system("tput clear");
					p("\n\nNo more elements to delete! Empty List!");
					break;
					}
					else
					delete_front(start);
					p("\n\nDo you want to delete another element(y/n) ");
					s(" %c",&ans);
				}while(ans=='Y'||ans=='y');
				break;
				
			case '3':
				//system("tput clear");
				if(start==NULL) p("\n\nEmpty List!");
				else
				{
					printf("\nThe list is:\n")
					;display(start);
				}
				
				break;
				
			case '4':
				return 0;
				
			case '5':
				//system("tput clear");
				break;
			
			default:
				printf("\nWrong Choice!");
		}
	}
	return 0;
}

struct node * create_node(int d)
{
	ptr = malloc(sizeof(struct node));
	ptr->data = d;
	ptr->next = NULL;
	return ptr;
}

void insert_fron(struct node *np)
{
	if(start == NULL)
	{
		start = np;
	}
	else
	{
		np->next=start;
		start=np;
	}
}

void display(struct node *np)
{
	while(np!=NULL)
	{
		p("%d->",np->data);
		np = np->next;
	}
}

void delete_front(struct node *np)
{
	p("\n");
	np = np->next;
	start = np;
	p("\nThe new list is:\n");
	display(start);
}

