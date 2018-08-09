#include<stdio.h>
#include<omp.h>

void main(){
int i, x[4];

#pragma omp parallel for shared(x)
	for(i=0;i<4;i++)
	{
		x[i] = x[i]+i;
		printf("Thread%d is the value of x - %d\n", i, x);
	}

}

