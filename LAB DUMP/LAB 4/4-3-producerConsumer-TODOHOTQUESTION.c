#include<stdio.h>
#include<omp.h>

int produce(int x)
{
	x = x+1;
	//printf("Producer producing. X value = %d\n", x);
	return x;
}

int consume(int x)
{
	x = x-1;
	//printf("Consumer consuming. X value = %d\n", x);
	return x;
}

int main()
{

int x=0;
int i;
for(i=0;i<4;i++)
{
printf("Loop no: %d\n", i);
#pragma omp sections
{
	#pragma omp section
	{
		#pragma omp critical
		x = produce(x);

		printf("Producer producing. X value = %d\n", x);
	}
	#pragma omp section
	{
		#pragma omp critical
		x = consume(x);


		printf("Consumer consuming. X value = %d\n",x);
	}
}
}
}


