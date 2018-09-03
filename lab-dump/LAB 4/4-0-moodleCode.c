//
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
		area+=4.0/(1.0+x*x);
	}
	pi=area/n;
	printf("Pi value is %f\n",pi);
}
