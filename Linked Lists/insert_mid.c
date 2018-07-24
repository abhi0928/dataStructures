#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int value,pos;

struct node{				
	int data;
	struct node *next;
}*start,*rear,*ptr,*ptr1;

void create_node();		

void insert_end();		

void display();			

void delete_front();

void insert_mid(struct node*);

void delete_mid(struct node*);	

int main()
{
	char choice;
	
	start=NULL;							
	while(1)
	{
		p("\n\nOperations on Queue using Linked List:\n");
		p("\n1.Insert elements.\n2.Insert at any position.\n3.Delete elements.\n4.Delete from any position.\n5.Display elements.\n6.Clear Screen.\n7.Exit.\n\nEnter your choice[1-5]: ");
		s(" %c", &choice);
		switch(choice)
		{
			case '1':
				//system("tput clear");
				system("cls");
				p("\nEnter a value: ");
				s("%d",&value);
				create_node();
				insert_end();
				p("\nThe list is:\n");
				display();
				break;
				
			case '3':
				if(start==NULL){
					//system("tput clear");
					system("cls");
					p("\nNo elements to delete! Empty List!");
				}
				else
				{
					if(start==NULL){
					//system("tput clear");
					system("cls");
					p("\n\nNo more elements to delete! Empty List!");
					break;
					}
					else
					delete_front();
				}
				break;
				
			case '5':
				//system("tput clear");
				system("cls");
				if(start==NULL) p("\n\nEmpty List!");
				else
				{
					printf("\nThe list is:\n");
					display();
				}
				break;
			
			case '2':
				p("\nEnter the position where you want to insert: ");
				s("%d",&pos);
				p("\nEnter a value: ");
				s("%d",&value);
				create_node();
				insert_mid(start);
				p("\nThe list is:\n");
				display();
				break;

			case '4':
				if(start==NULL){
					//system("tput clear");
					system("cls");
					p("\nNo elements to delete! Empty List!");
				}
				else
				{
					if(start==NULL)	printf("No more elements to delete!");
					else{
					p("\nEnter the position from where you want to delete: ");
					s("%d",&pos);
					delete_mid(start);
					p("\nThe new list is:\n");
					display();
					}
				}
				break;
				
			case '7':
				return 0;
				
			case '6':
				//system("tput clear");
				system("cls");
				break;
			
			default:
				printf("\nWrong Choice!");
		}
	}
	return 0;
}

void create_node()
{
	ptr =(struct node*)malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
}

void insert_end()
{
	if(start == NULL)
	{
		start = ptr;
		rear = ptr;
	}
	else
	{
		rear->next = ptr;
		rear = ptr;
	}
}

void display()
{
	struct node*np = start;
	while(np!=NULL)
	{
		p("%d->",np->data);
		np = np->next;
	}
}

void delete_front()
{
	p("\n");
	start = start->next;
	p("\nThe new list is:\n");
	display();
}

void insert_mid(struct node *np)
{

	int count=0;
	if(pos == 1)
	{
		ptr->next = start;
		start = ptr;
	}
	else
	{
		while(np!=NULL)
		{
			count++;
			if(count==pos-1)
			{
				ptr->next = np->next;
				np->next = ptr;
				break;
			}
			np = np->next;
		}
		if(pos > count+1)	printf("\nInvalid Postion!\n");
	}
}

void delete_mid(struct node *np)
{

	int count=0;
	if(pos == 1)
	{
		start = start->next;
	}
	else
	{
		while(np!=NULL)
		{
			count++;
			if(count==pos-1)
			{
				ptr1 =np;
				np = np->next;
				break;
			}
			np = np->next;
		}
		ptr1->next = np->next;
		if(pos > count+1)	printf("\nInvalid Postion!\n");
	}
}


