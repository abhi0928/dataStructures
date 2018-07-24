#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int pos,l;

typedef struct node{
         int data;
         struct node *left,*right;
}node;

node *create,*front,*rear;

int len(node *temp)
{
	int c = 0;
	while(temp!=NULL){
		c++;
		temp = temp->right;
	}
	return c;
}

void create_node()
{
   create = (node *)malloc(sizeof(node));
   create->left = NULL;
   create->right = NULL;
}

void insert()
{
   if(front == NULL)
   {
      front = create;
      rear = create;
   }
   else
   {
    node *temp = front;
	p("Enter the position: ");
	s("%d",&pos);
	l = len(front);
	if(pos<=1){
		create->right = front;
		front->left = create;
		front = create;
	}

	else if(pos>=l+1){
		create->left = rear;
		rear->right = create;
		rear = create;
	}
	else
	{
		int c = 0;
		while(temp!=NULL)
		{
			c++;
			if(c==pos-1)
			{
				create->right = temp->right;
				create->left = temp;
				temp->right = create;
				temp = create->right;
				temp->left = create;
				break;
			}
			temp = temp->right;
		}
	}
   }
}

void display(node *temp)
{
   if(temp!=NULL)
   {
     p("<-%d->",temp->data);
     display(temp->right);
   }
}


void display_rev(node *temp)
{
   if(temp!=NULL)
   {
     p("<-%d->",temp->data);
     display_rev(temp->left);
   }
}

void delete()
{
   if(front == NULL) p("Error! Situation Underflow!");
   else
   {
      if(front == rear)
      {
         front = NULL;
         rear = NULL;
         p("Empty!");
      }
      else
      {
         rear = rear->left;
         rear->right = NULL;
      }
   }
}

int main()
{
   char c;
   front = NULL;
   while(1)
   {
      p("\n\n============================Double Linked Lists============================");
      p("\n1.Insert.\n2.Delete.\n3.Traverse.\n4.Traverse in reverse order.\n5.Exit.\nEnter your choice: ");
      s(" %c",&c);
      switch(c)
      {
         case '1':
         	//system("cls");
         	create_node();
            p("Enter the value: ");
            s("%d",&create->data);
            insert();
            display(front);
            break;
         
         case '2':
            delete();
            display(front);
            break;
            
         case '3':
            //system("tput clear");
            system("cls");
            if(front == NULL) p("No Elements to display!");
            else  display(front);
            break;
         
         case '4':
         	if(front == NULL) p("No Elements to display!");
            else  display_rev(rear);
            break;

         case '5':
            return 0;
         
         default: p("Wrong Choice!");
      }
   }
   return 0;
}
