//Code to find out the Pi value using Monte Carlo algorithm
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
int main()
{
  int i,count;
	unsigned short a[3];
	int samp;
	double x,y;
	double pi;
	scanf("%d",&samp);
	#pragma omp parallel
	{
		a[0]=1;
		a[1]=1;
		a[2]=omp_get_thread_num();
  	count=0;
		printf("Thread %d\n",a[2]);
		#pragma omp for firstprivate(a) private(x,y) reduction(+:count)
		for(i=0;i<samp;i++)
		{
			x=erand48(a);
			y=erand48(a);
			if(x*x+y*y<=1.0)
        count++;
		}
	}
	pi=4.0*(double)count/(double)samp;
	printf("Count= %d, Sample=%d, Pi estimate = %.5f \n", count, samp, pi);
}