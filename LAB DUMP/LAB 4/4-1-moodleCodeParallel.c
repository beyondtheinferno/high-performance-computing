//Parallelized for, prints different value of pi
#include <stdio.h>
#include<omp.h>
int main()
{
	double area, pi, x;
	int i,n;
	area=0.0;
	n=100;
	#pragma omp parallel for
	for (i=0;i<n;i++)
	{
		x=(i+0.5)/n;
		#pragma omp critical
		area+=4.0/(1.0+x*x);
	}
	pi=area/n;
	printf("Pi value is %f\n",pi);
}



/*

Multiple threads are accessing same global variable, hence each thread will take different value and we'll get different value for each execution. Hence we use critical section.

|| #pragma omp critical || -> The line following this is a critical section and hence can't be accessed at the same time by multiple threads.

*/

