#include<stdio.h>

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

for(num=2; num*num<n; num++)
{
	if(yn[num] == 1)
	{
		for(i=num*2; i<=n; i+=num)
		{
			yn[i] = 0;
		}
	}
}

printf("Prime numbers are - \n");
for(i=1;i<=n;i++)
{	
	if(yn[i] == 1)
		printf("Number - %d\n", prime[i]);
}
}
