#include<stdio.h>
#include<omp.h>

void main(){
int tid, no, i;
int x[4] = {0,0,0,0};
int out[4] = {0,0,0,0};

#pragma omp parallel private(tid)
{
tid = omp_get_thread_num();
printf("TID%d\n", tid);
if(tid==0)
{
	no = omp_get_num_threads();
}
#pragma omp for 
	for(i=0;i<no;i++)
	{
		printf("TID%d doing job %d\n",tid, i);
	}

}
}

/*
Work sharing construct - Each thread does different work and code is not just copied across all threads
|| #pragma omp for || -> for loop following the constraint is to be parallelized

|| #pragma omp parallel for || -> works only for one thread

*/
