//reduction() usage
#include<omp.h>
#include<stdio.h>
int main(){
int x = 100;
int i;
int y;
int sum = 0;
#pragma omp parallel for firstprivate(x) lastprivate(y) reduction(+:sum)
for(i=0;i<4;i++)
{
	x = x+i;
	y = x;
	sum = sum + y;
	printf("y value = %d\n", y);
	printf("Sum inside the threads = %d\n", sum);
}
printf("Sum = %d", sum);
}

/*

All the threads will execute the sum statement inside individually as private variables.

|| reduction(+:sum) || -> will get the sum value in each thread and add them, store the value in variable sum. Final product can be obtained after the execution of all threads in the main thread

|| reduction(*:product) || -> will get the value in the product variable from each thread and multiply them, store the value in the variable product. Final product can be obtained after the execution of all threads in the main thread

*/
