#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void permute(int *a, int l, int r)
{
	if(l==r)
	{
		for(int i=0; i<=r; i++)	cout<<*(a+i)<<" ";
		cout<<endl;
	}
	else
	{
		for(int i=l; i<=r; i++)
		{
			swap(a+l,a+i);
			permute(a, l+1, r);
			swap(a+l,a+i);
		}
	}
}

int main()
{
	int a[] = {1,2,3,4};
	permute(a, 0, sizeof(a)/sizeof(a[0])-1);
	return 0;
}
