#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int main()
{
	int n,i,j,k,min,temp;
	p("Enter the size of the array: ");
	s("%d",&n);
	int a[n];
	p("Enter %d elements of the array:\n",n);
	for(i=0;i<n;i++)	s("%d",&a[i]);
	
	for(i=0;i<n-1;i++)
	{
		min = a[i+1];
		for(j=i+2;j<n;j++)
		{
			if(min>a[j])
			{
				min = a[j];
				k = j;
			}
		}
		if(a[k]<a[i])
		{
			temp = a[k];
			a[k] = a[i];
			a[i] = temp;
		}
	}
	
	p("The sorted array is:\n");
	for(i=0;i<n;i++)	p("%d ",a[i]);
	p("\n");
	return 0;
}
