#include<stdio.h>
#include<omp.h>

void main(){
int tid, no, i;
int x[4];
x[2] = 0;

#pragma omp parallel for firstprivate(x)
	for(i=0;i<4;i++)
	{
		printf("Thread%d value of x is %d\n", i, x[i]);		
		x[i] = x[i]+i;
		printf("Thread%d value of x is %d\n", i, x[i]);
	}


}

/*

firstprivate(x) - if we assign any one value of the array above threads, then that value will be assigned to other array positions too.

*/
