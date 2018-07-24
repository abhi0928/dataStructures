#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf
#define f for

int sz,fr=-1,r=-1,d,i;

void display(int q[]);
void insert(int q[]);
void delete(int q[]);

int main()
{
	char ans;
	int ch;

	p("\nEnter the size of the stack: ");
	s("%d",&sz);
	
	int q[sz];
	
	while(1)
	{
		p("\n\n****************Program on Stack****************");
		p("\n1.Push elements.\n2.Pop elements.\n3.Display.\n4.Clear Screen.\n5.Exit.\nEnter your choice: ");
		s("%d",&ch);
		switch(ch)
		{
			case 1:
				do
				{
				p("\nEnter a value: ");
				s("%d",&d);
				insert(q);
				p("\nThe list is:\n");
				display(q);
				if(fr==sz-1) break;
				p("\nDo you want to enter another number? (y/n) ");
				s(" %c",&ans);
				}while(ans=='y'||ans=='Y');
				break;

			case 2:
				do
				{
					if(fr==-1)
					{
						p("\nUnable To delete! Situation Underflow!");
						break;
					}
					delete(q);
					if(fr==-1) break;
					display(q);
					p("\nDo you want to delete another element? (y/n) ");
					s(" %c",&ans);
				}while(ans=='y'||ans=='Y');
				break;
			
			case 3:
				if(fr==-1) p("\nEmpty List!");
				else
				{
					p("\nThe list is:\n");
					display(q);
				}
			break;

			case 5:
				return 0;

			case 4:
				system("tput clear");
				break;

			default:
				p("\nWrong Choice!");
		}
		
	}
	return 0;
}

void display(int q[])
{
	f(i=fr;i>=r;i--) p("%d\n",q[i]);
}

void insert(int q[])
{
	if(fr==sz-1)
	{
		p("\nValue not entered! Situation Overflow!");
	}
	else if(fr==-1)
	{
		fr=0;
		r=0;
		q[fr]=d;
	}
	else
	{
	 fr++;
	 q[fr]=d;
	}
}

void delete(int q[])
{
	fr-=1;
	p("\nThe new list is:\n");
}
