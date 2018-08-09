//

#include<stdio.h>
#include<omp.h>
int main()
{
	int i, j, m,n;
	int low,high;
	n=10;
	int a[10] = {1,1,1,1,1,1,1,1,1,1};
	int b[10] = {0,0,0,0,0,0,0,0,0,0};
	int c[10];
	#pragma omp parallel
	for (i=0;i<n;i++)
	{
		low=a[i];
		high=b[i];
		if (low>high)
		{
			printf("Exiting\n");
			break;
		}
		for (j=low;j<high;j++)
			c[j]=(c[j]-a[i])/b[i];
	}
}

/*
|| #pragma omp single || -> When you want only one of the threads to execute the command. Does not work with parallel for.

|| #pragma omp master || -> Only master thread will execute that command

*/
