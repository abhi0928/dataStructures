#include<stdio.h>
#include<stdlib.h>

#define p printf
#define s scanf

int main()
{
	int n,i,j;
	p("Enter the size of the array: ");
	s("%d",&n);
	int a[n];
	p("Enter %d elements of the array:\n",n);
	for(i=0;i<n;i++)	s("%d",&a[i]);

	for(i=0;i<n-1;i++)
	{
		int flag = 0;
		for(j=0;j<(n-1)-i;j++)
		{
			if(a[j]>a[j+1])
			{
				flag=1;
				int temp;
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		if(flag==0) break;
	}
	p("The sorted array is:\n");
	for(i=0;i<n;i++)	p("%d ",a[i]);
	p("\n");
	return 0;
}
