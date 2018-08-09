//Sieve of Erathosthenes using SECTIONS and SECTION
#include<stdio.h>
#include<omp.h>
int sieve(int yn[50], int num, int n)
{
	int i;	
	if(yn[num] == 1)
	{
		for(i=num*2; i<=n; i+=num)
		{
			yn[i] = 0;
		}
	}
}
int main(){

int prime[50];
int yn[50];
int n = 10;
int i, num;
for(i=1;i<=n;i++)
{	
	prime[i] = i;
	yn[i] = 1;
}

#pragma omp sections
{
	#pragma omp section
	{
		sieve(yn, 2, n);
	}
	#pragma omp section
	{
		sieve(yn, 3, n);
	}
}
printf("Prime numbers are - \n");
for(i=1;i<=n;i++)
{	
	if(yn[i] == 1)
		printf("Number - %d\n", prime[i]);
}
}
