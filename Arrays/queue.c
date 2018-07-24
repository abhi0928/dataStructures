#include<stdlib.h>
#include<stdio.h>

#define p printf
#define s scanf
#define f for

int size,front,rear,data,counter;

void delete(int queue[]);

void display(int queue[]);

int main()
{
   char ans,ch;
   
   p("\nEnter the size of the queue: ");
   s("%d",&size);
   int queue[size];
   front=-1,rear=-1;
      
   while(1)
   {
    p("\n\n********Program on Queue!********\n");
    p("1.Insert.\n2.Delete.\n3.Exit.\nEnter your choice: ");
    s(" %c",&ch);
    switch(ch)
    {
     case '1':
         do
         {
          p("\nEnter a value: ");
          s("%d",&data);
          if(rear==size)
          {
           p("\nValue not entered! Situation Overflow!");
           break;
          }    
          else if(front==-1&&rear==-1)
          {
             front++;
             rear++;
             queue[rear]=data;
             rear++;
          }
          else
          {
          queue[rear]=data;
          rear++;
          }
          p("\nThe list is:\n");
          display(queue);
          p("\nDo you want to enter another value(y/n): ");
          s(" %c",&ans);
         }while(ans=='y'||ans=='Y');
         break;
     
     case '2':
         if(front==-1||front==size)
            {
             p("\nNo elements to delete! Situation Underflow!");
             break;
            }
         else
         do{
            if(front==size)
            {
             p("\nNo more elements to delete! Situation Underflow!");
             break;
            }
            else
            delete(queue);
            p("\nThe new list is:\n");
            display(queue);
            p("\nDo you want to delete another element(y/n): ");
            s(" %c",&ans);
           }while(ans=='y'||ans=='Y');
         break;
     
     case '3':
         return 0;
      
     default:
         p("\nWrong Choice!");
    }
   } 
   return 0;
} 

void display(int queue[])
{
   f(counter=front;counter<rear;counter++)
    p("%d ",queue[counter]);
}  

void delete(int queue[])
{
 front++;
}
  
