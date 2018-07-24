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
	p("\nEnter the size of the queue: ");
	s("%d",&sz);
	int q[sz],ch;
	
	while(1)
	{
		p("\n\n****************Program on Circular Queue****************");
		p("\n1.Insert.\n2.Delete.\n3.Display List.\n4.Clear Screen.\n5.Exit.\nEnter your choice: ");
		s("%d",&ch);
		switch(ch)
		{
			case 1:
				r=(r+1)%sz;
				p("\nEnter a value: ");
				s("%d",&d);
				insert(q);
				p("\nThe list is:\n");
				display(q);
				if(r==sz-1) break;
				break;

			case 2:
					if(fr==-1)
					{
						p("\nUnable To delete! Situation Underflow!");
						break;
					}
					delete(q);
					if(fr==-1) break;
					display(q);
				break;
			
			case 3:
				p("\nThe list is:\n");
				display(q);
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
	f(i=fr;i<=r;i++) p("%d ",q[i]);
}

void insert(int q[])
{
	if(fr==r)
	{
		p("\nValue not entered! Situation Overflow!");
		r=sz-1;
	}
	else if(fr==-1)
	{
		fr=0;
		q[r]=d;
	}
	else q[r]=d;
}

void delete(int q[])
{
	if(fr==r) {fr=-1; r=-1;}
	else if(fr==sz-1) fr=0;
	else fr++;
	p("\nThe new list is:\n");
}
