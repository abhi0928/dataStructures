#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("\nEnter the size of the array: ");
	scanf("%d",&n);
	int a[n],i,j,temp,val;
	
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	printf("\nThe sorted array is:\n");
	for(i=0;i<n;i++) printf("%d ",a[i]);
	
	printf("\nEnter the value you want to search for: ");
	scanf("%d",&val);
	
	int lo=0,hi=n-1,mid,flag=0;
	while(lo<=hi)
	{
		mid=(lo+hi)/2;
		if(a[mid]==val)
		{
			flag=1;
			printf("\nValue %d found at position [%d] of the array.\n",val,mid);
			break;
		}
		else if(a[mid]<val)	lo=mid+1;
		else hi=mid-1;
	}
	if(flag==0)	printf("\nValue not found!");
	
	return 0;
}
