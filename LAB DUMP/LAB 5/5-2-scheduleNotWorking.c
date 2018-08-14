/*

Consider - 
```
#pragma omp parallel for
for(i=0;i<n;i++)
	for(j=i;j<n;j++)
		a[i][j] = 2;
```
Thread 0 will execute more tasks than other threads, thread 1 will execute less than 0 and more than rest, and so on... This puts more load on some threads and less on some. 

Things that we should look while parallelizing - 
1. Spatial and temporal locality - Seen already
2. Check if parallization is necessary using `prallel for if` - Seen already

3. Scheduling -> Static, Dynamic and Guided


Def ===
1. static -> Before execution itself, if n is entirely div by p, it will schedule first n/p tasks sequentially to first thread. If n is not entirely div by p, then some will execute floor of n/p and some will execute ceil of n/p. ANd then allocate the tasks to threads.

2. (dynamic,3) -> 20 tasks to be done, then first to first thread, second to second thread, third to third thread. Whichever thread finishes, next job will be allocated to that thread.

3. (guided) -> heuristic


If n is completely div by p, and computation is identical for each task, static execution time is less than dynamic execution time.


|| #pragma omp parallel for schedule(type-of-schedule, chunk-size) || -> For scheduling
Chunk size -> it is the n/p value 

|| #pragma omp parallel for schedule(runtime) || -> You'll be setting the parameters during runtime from terminal using env variables. To set those env variables use
|| OMP_SCHEDULE "static,3" ||


*/

#include<stdio.h>
#include<omp.h>
int main()
{
	int a[10][10];
	int m = 10;
	int n = 10;
	int i,j;
	
	//clock_t begin = clock();
	#pragma omp parallel for schedule(dynamic)
	for(i=0;i<n;i++)
	{
		int tid	= omp_get_thread_num();
		for(j=0;j<m;j++)
		{
			a[i][j] = 2;
			printf("Thread ID = %d, a[%d][%d]=%d \n",tid, i,j,a[i][j]);
		}
		printf("Thread ID=%d has completed\n",tid);
	}

	
	//clock_t end = clock();
	//double time_spent = (double)(end-begin)/ CLOCKS_PER_SEC;
	//printf("Time taken to execute = %lf", time_spent);
}
