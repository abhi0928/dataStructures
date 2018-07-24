#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int main()
{
	int n,i,j,temp;
	p("Enter the size of the array: ");
	s("%d",&n);
	int a[n];
	p("Enter %d elements of the array:\n",n);
	for(i=0;i<n;i++)	s("%d",&a[i]);
	
	for(i=1;i<=n;i++)
	{
		for(j=i-1;j>0;j--)
		{
			if(a[j-1]>a[j])
			{
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	}
	
	p("The sorted array is:\n");
	for(i=0;i<n;i++)	p("%d ",a[i]);
	p("\n");
	return 0;
}

