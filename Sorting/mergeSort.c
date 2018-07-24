#include<stdio.h>

void merge(int[],int,int,int);

void mergeSort(int a[],int l,int r)
{
	if(l<r)
	{
		int m = (l+r)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,r);
		merge(a,l,m,r);
	}
}

void merge(int a[],int l,int m,int r)
{
	int i,j,k;
	
	int n1 = m-l+1;
	int n2 = r-m;
	int L[n1],R[n2];
	
	for(i=0;i<n1;i++)	L[i]=a[i+l];
	for(j=0;j<n2;j++)	R[j]=a[j+m+1];
	
	for(i=0,j=0,k=l;k<=r;)//i<n1&&j<n2;)
	{
		if(i>=n1){
			a[k] = R[j];
			j++;
		}
		else if(j>=n2){
			a[k] = L[i];
			i++;
		}
		else{
			if(L[i]>R[j])
			{
				a[k] = R[j];
				j++;
			}
			else{
				a[k] = L[i];
				i++;
			}
		}
		k++;
	}
	
	/*while(i<n1){
		a[k] = L[i];
		k++;
		i++;
	}
	
	while(j<n2){
		a[k] = R[j];
		k++;
		j++;
	}*/
}

int main()
{
	int n;
	
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	int a[n],i;
	
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)	scanf("%d",&a[i]);
	
	mergeSort(a,0,n-1);
	
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)	printf("%d ",a[i]);
	printf("\n");
	
	return 0;
}




