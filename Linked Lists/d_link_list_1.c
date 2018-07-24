#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int pos;

struct node{
         int data;
         struct node *left,*right;
}*create,*front,*rear;

typedef struct node node;

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
	if(pos<=1){
		create->right = front;
		front->left = create;
		front = create;
	}

	else if(pos>=len(front)+1){
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

void delete(node *temp)
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
      	 p("Enter the position: ");
      	 s("%d",&pos);
      	 if(pos<=1){
      	 	front = front->right;
      	 	front->left = NULL;
      	 }
      	 else if(pos>=len(front)){
      	 	rear = rear->left;
      	 	rear->right = NULL;
      	 }
      	 else{
      	 	node *ptr;
      	 	int c = 0;
         	while(temp!=NULL)
         	{
         		ptr = temp->right;
         		c++;
         		if(c==pos-1){
         			temp->right = ptr->right;
         			ptr = ptr->right;
         			ptr->left = temp;
         			break;
         		}
         		temp = temp->right;
         	}
      	 }
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
            delete(front);
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
