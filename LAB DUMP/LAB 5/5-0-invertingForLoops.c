/*
For parallelized programs - make sure you follow spatial and temporal locality. Normal execution will compile in row major. But (consider you declare for loop with i first and then for of j inside it) when we give a[j][i] -> a[0][0] followed by a[1][0] which is a column major. This will force the compiler to fetch new blocks of memory into the cache for every single step, huge cost time wise. So invert the for loops for proper time efficient execution.

OUTPUTS - 
Before inverting - 1.433797
After inverting - 1.480788


*/
#include<stdio.h>
#include<omp.h>
#include<time.h>

int main()
{
	int a[1000][1000];
	int m = 1000;
	int n = 1000;
	int i,j;
	
	clock_t begin = clock();

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			a[i][j] = 2;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("a[%d][%d] = %d\n", j,i,a[i][j]);
		}
		printf("\n");
	}
	
	clock_t end = clock();
	double time_spent = (double)(end-begin)/ CLOCKS_PER_SEC;
	printf("Time taken to execute = %lf", time_spent);
}	


