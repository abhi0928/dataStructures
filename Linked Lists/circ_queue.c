#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

struct node{				//definition of structure to implement linked list
	int data;
	struct node *next;
}*start,*rear,*ptr,*newptr;

struct node * create_node(int d);		//function to create a node and and enter data into it

void insert_end(struct node *np);		//function to link two nodes

void display(struct node *np);			//function to display elements of the list

void delete_front();		//function to delete elements of the list

int main()
{
	int value;
	char choice,ans;
	
	start=rear=NULL;							//at first start pointer points to NULL
	while(1)
	{
		p("\n\nOperations on Queue using Linked List:\n");
		p("\n1.Push elements.\n2.Pop elements.\n3.Display elements.\n4.Exit\n5.Clear Screen\n\nEnter your choice[1-5]: ");
		s(" %c", &choice);
		switch(choice)
		{
			case '1':
				system("tput clear");
				p("\nEnter a value: ");
				s("%d",&value);
				newptr = create_node(value);
				insert_end(newptr);
				p("\nThe list is:\n");
				display(start);
				break;
				
			case '2':
			   system("tput clear");
				if(start==rear)
				{
				 p("\nThe new list is Empty!");
				 start=rear=NULL;
				}
				else
				{
				 delete_front();
				 p("\nThe new list is:\n");
				 display(start);
				}
				break;
				
			case '3':
				system("tput clear");
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
				system("tput clear");
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

void insert_end(struct node *np)
{
	if(start == NULL)
	{
		start = np;
		rear = np;
		rear->next = start;
	}
	else
	{
		rear->next = np;
		rear = np;
		rear->next = start;
	}
}

void display(struct node *np)
{
	do
	{
		p("%d->",np->data);
		np = np->next;
	}while(np!=start);
}

void delete_front()
{
	ptr=start;
	if(start==NULL)
	{	
		system("cls");
		p("\nNo elements to delete! Situation Underflow!");
	}
	else
	{
		start=start->next;
		rear->next=start;
		ptr->next=NULL;
		free(ptr);
	}
}

