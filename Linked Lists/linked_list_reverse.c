#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf
#define f for

int val;

typedef struct node{
      int data;
      struct node *next;
}node;

node *create,*front,*rear;
         
void create_node();

void insert_node();

void display(node *);

void delete();

void rev_list(node *);

int main()
{
 char ch;
 front=NULL;
 
 while(1)
 {
	 p("\n\n******Program on nexted Lists!******\n");
	 p("\n1.Insert.\n2.Delete.\n3.Recursive Traversal.\n4.Reverse the List.\n5.Clear Screen.\n6.Exit.\nEnter your choice: ");
	 s(" %c",&ch);
	 switch(ch)
	 {
	  case '1':
	       p("\nEnter value: ");
	       s("%d",&val);
	       create_node();
	       insert_node();
	       p("\nThe list is:\n");
	       display(front);
	      break;
	  
	  case '2':
	       if(front==NULL)
	       {
	        p("\nCondition Underflow! No elements to delete!\n");
	        break;
	       }
	       else
	       {
	        p("\nThe new list is:\n");
	        delete();
	       }
	      break;
	  
	  case '3':
	  	p("\nThe list is:\n");
	    display(front);
	    break;
	  
	  case '4':
	  	rev_list(front->next);
	  	p("\nThe reversed list is:\n");
	  	display(front);
	  	break;
	  
	  case '5':
	    system("cls");
		//system("tput clear");
	    break;
	  
	  case '6':
	  	return 0;
	  
	  default:
	      p("\nWrong Choice!");
	 }
	 }
	 return 0;
}
	
void create_node()
{
 create = malloc(sizeof(struct node));
 create->data = val;
 create->next=NULL;
}
	
void insert_node()
{
 if(front==NULL)
 {
  front=create;
  rear=create;
 }
 else
 {
  rear->next = create;
  rear = create;
 }
}
	
void display(struct node *temp)
{
 if(temp!=NULL)
 {
  p("%d->",temp->data);
  display(temp->next);
 }
}
	 
void delete()
{
  front = front->next;
  display(front);
}

void rev_list(node *temp)
{
	node *ptr;
	rear = front;
	rear->next = NULL;
	
	while(temp!=NULL)
	{
		ptr = temp->next;
		temp->next = front;
		front = temp;
		temp = ptr;
	}
}
