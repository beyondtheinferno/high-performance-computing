#include<stdio.h>
#include<omp.h>

int main()
{
int n = 10;
int i,j=0,a[10],k,tid;
n=n-1;
for(i=0;i<n;i++)
{
	a[i]=i+2;
}

#pragma omp parallel for private(tid) shared(a) 
for(j=0;j<n;j++)
{
 	for(k=j+1;k<n;k++)
	{
 		if(a[k]!=0 && a[j]!=0)
		{
 			if(a[k]%a[j]==0)
 				a[k]=0;
 		}
 	}
}

printf("Prime numbers less than N are -> \n");
for(i=0;i<n;i++)
	if(a[i]!=0)
		printf("%d\n",a[i]);
}
