//Private and Shared variables
#include<omp.h>
#include<stdio.h>

int main(){

int x = 5;
int i;
#pragma omp parallel for private(x)
for(i=0;i<4;i++)
{
	printf("X value = %d\n",x);
	x = x+1;
	printf("Private x value - %d\n", x);
}

printf("After x value - %d", x);

}







/*
Work Sharing Constraint -> Total no of threads is 3. First thread with id = 0 -> i value will be 0 and (id,i)=(1,1) and so on due to parallel for. Index variable for a for will be a private variable always. Each thread will have separate memory locations for i and it will be visible only to that thread.

Shared variable - x here. When thread 0 runs, x value will be 0. When thread 2 runs, x value is 2. And so on. The last executed thread will store the value in x finally.
Private variable - value of private variable is local to every thread

If the value of the loop range is given more than the no of threads -> the thread which completes first, next task will be assigned to it.

*/
