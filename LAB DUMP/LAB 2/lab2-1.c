#include<stdio.h>
#include<omp.h>

void main(){
int tid, no, i;
int x[4];
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
		x[i] = 0;
		x[i] = x[i]+i;
		printf("Thread%d,%d value of x - \n", tid, x);
	}

}
}


/*
Variables can be either shared or private variables in OpenMP. If no declaration, by default they are shared variables except index variables (i.e. i). Memory space will be given for i in each thread separately. FOR LOOP INDEX VARIABLES SHOULD BE PRIVATE!!

ANy thread can access the array x (shared). But the index variable used to reference x is private.


*/
