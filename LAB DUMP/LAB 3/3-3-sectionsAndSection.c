//Parallelization using Sections and section
#include<omp.h>
#include<stdio.h>

int main(){

int a=5, b=3;
int sum, diff, prod;

#pragma omp sections
{
	#pragma omp section
	{
		sum = a+b;
		printf("Sum = %d\n", sum);
	}
	#pragma omp section
	{
		diff = a-b;
		printf("Difference = %d\n", diff);
	}
	#pragma omp section
	{
		prod = a*b;
		printf("Product = %d\n", prod);
	}
}

}



/*

|| #pragma omp sections || -> each section inside the following flower brackets will be executed parallelly.

|| #pragma omp section || -> declare a section to be executed parallelly inside sections declaration

*/
