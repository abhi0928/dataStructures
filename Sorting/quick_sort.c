#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

void swap(int *p,int *q)
{
	int t = *p;
	*p = *q;
	*q = t;
}

int partition(int a[],int p,int t)
{
	int x = a[t];
	int i = p-1;
	int j;
	for(j=p;j<t;j++)
	{
		if(a[j]<=x)
		{
			i++;
			if(a[j]!=a[i])
			swap(&a[j],&a[i]);
		}
	}
	swap(&a[i+1],&a[t]);
	return(i+1);
}

void quicksort(int a[],int p,int t)
{
	if(p<t)
	{
		int q = partition(a,p,t);
		quicksort(a,p,q-1);
		quicksort(a,q+1,t);
	}
}

int main()
{
	int n,i;
	p("Enter the size of the array: ");
	s("%d",&n);
	int a[n];
	p("Enter %d elements of the array: ",n);
	for(i=0;i<n;i++)	s("%d",&a[i]);
	quicksort(a,0,n-1);
	p("The sorted array is:\n");
	for(i=0;i<n;i++)	p("%d ",a[i]);
	return 0;
}
