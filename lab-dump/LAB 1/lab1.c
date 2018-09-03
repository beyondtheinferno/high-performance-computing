#include<stdio.h>
#include<omp.h>

void main(){
int tid, no;
int message[4] = {0, 1, 2, 3};
#pragma omp parallel private(tid)
{
tid = omp_get_thread_num();
printf("\nHello World! - %d\n", tid);

printf("TID - %d, MESSAGE - %d", message[tid]);
/*
if(tid == 0)
{
	no = omp_get_num_threads();
	printf("No. of threads - %d", no);
}

if(tid == 1)
{
	printf("This is thread 1!");
}

if(tid == 2)
{
	printf("This is thread 2!");
}

if(tid == 3)
{
	printf("This is thread 3!");
}
*/
}
}

/*

local variable ->
global variable ->
env variable -> variable value is stored across programs, held by OS. 

Variable for no of threads - should be integer, env variable
|| export OMP_NUM_THREADS=2 || -> export is a linux command. OMP_NUM_THREADS - predefined env variable in OMP

|| #pragma omp parallel private(tid) || -> #pragma omp parallel is a construct in C code. Copies the code block containing printf into all the threads and executes it. 
private(tid) -> creates the tid variable privately for each threads. Without it, all threads will share a common tid variable, and hence they won't satisfy following conditions

|| gcc -fopenmp lab1.c || -> instructs the compiler to make use of OpenMP while compiling this C file

|| gcc -fopenmp lab1.c -o lab1 || -> creates object file with name "lab1.out" instead of standard "a.out". Use || ./lab1 || to run the execute the obj file

Ideal no. of threads - 4

|| tid = omp_get_thread_num(); || -> gets the thread id of the current thread, where tid is an integer variable. The order of execution of threads is random, so the value of "tid" will be random.

|| no = omp_get_num_threads(); ||

*/
