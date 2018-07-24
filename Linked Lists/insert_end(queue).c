#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int value,count;

struct node{				
	int data;
	struct node *next;
}*start,*rear,*ptr,*ptr1,*ptr2;

void create_node();		

void insert_end();		

void display(struct node *np);			

void delete_front();		

int main()
{
	char choice;
	
	start=NULL;							
	while(1)
	{
		p("\n\nOperations on Queue using Linked List:\n");
		p("\n1.Insert elements.\n2.Delete elements.\n3.Display elements.\n4.Insert at 4th position.\n5.Clear Screen.\n6.Exit.\n\nEnter your choice[1-5]: ");
		//s(" %c", &choice);
		choice = getch();
		switch(choice)
		{
			case '1':
				//system("tput clear");
				//system("cls");
				p("\nEnter a value: ");
				s("%d",&value);
				create_node();
				insert_end();
				p("\nThe list is:\n");
				display(start);
				break;
				
			case '2':
				if(start==NULL){
					//system("tput clear");
					//system("cls");
					p("\nNo elements to delete! Empty List!");
				}
				else
				{
					if(start==NULL){
					//system("tput clear");
					//system("cls");
					p("\n\nNo more elements to delete! Empty List!");
					break;
					}
					else
					delete_front();
				}
				break;
				
			case '3':
				//system("tput clear");
				//system("cls");
				if(start==NULL) p("\n\nEmpty List!");
				else
				{
					printf("\nThe list is:\n")
					;display(start);
				}
				
				break;
			
			case '4':
				
				break;
				
			case '6':
				return 0;
				
			case '5':
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
	count++;
	ptr = malloc(sizeof(struct node));
	ptr->data = value;
	ptr->next = NULL;
	if(count == 4)	ptr1 = ptr;
	if(count == 5)	ptr2 = ptr;
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

void display(struct node *np)
{
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
	display(start);
}

