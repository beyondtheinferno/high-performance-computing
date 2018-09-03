//WITH LASTPRIVATE(X)
#include<stdio.h>
#include<omp.h>

void main(){
int tid, no, i;
int x;

#pragma omp parallel for lastprivate(x)
	for(i=0;i<4;i++)
	{
		printf("Thread%d value of x is %d\n", i, x);		
		x = x+i;
		printf("Thread%d value of x is %d\n", i, x);
	}
printf("Value of x after completing execution of all threads - %d", x);

}

/*

lastprivate(x) - After execution of all threads, x value will be not predictable. Hence this command lets x have the value of the last executed thread if the threads were to be executed sequentially. For single variable values.

*/
