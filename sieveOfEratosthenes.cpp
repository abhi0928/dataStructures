#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	scanf("%d", &n);
	n+=1;
	int primes[n];
	for(int i=0; i<n; i++)	primes[i] = 1;
	primes[0]=0;
	primes[1]=0;
	
	for(int i=2; i<sqrt(n); i++)
	{
		if(primes[i])
		{
			for(int j=2; i*j<n; j++)
			{
				int k = i*j;
				primes[k]=0;
			}
		}
	}
	for(int i=0; i<n; i++)	if(primes[i])	printf("%d ",i);
	return 0;
}
