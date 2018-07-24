#include<stdio.h>
#include<string.h>

void lpsArray(char *pat, int M, int *lps);

void kmpSearch(char *pat, char *txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	
	int lps[M], FLAG=1;
	lpsArray(pat, M, lps);
	
	int i=0, j=0;
	while(i<N)
	{
		if(pat[j]==txt[i])
		{
			i++;
			j++;
		}
		if(j==M)
		{
			printf("Pattern found at index %d\n",i-j);
			j=lps[j-1];
			FLAG = 0;
		}
		else if(i<N && pat[j]!=txt[i])
		{
			if(j!=0)	j=lps[j-1];
			else	i++;
		}
	}
	if(FLAG)	printf("Pattern not found!\n");
}

void lpsArray(char *pat, int M, int *lps)
{
	lps[0]=0;
	int i=1, len=0;
	while(i<M)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)	len=lps[len-1];
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int main()
{
	char *txt = "ABCDAABCACBA";
	char *pat = "ABCAC";
	kmpSearch(pat, txt);
	return 0;
}
