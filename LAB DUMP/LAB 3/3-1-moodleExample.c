//Moodle example
#include<stdio.h>
#include<omp.h>
int main()
{
int x[4];
int answer[100];
int i,j;
int tid;
x[2]=100;
int y;
int sum=0;
# pragma omp parallel for private(i) firstprivate(x) lastprivate(y) reduction(+:sum)
for(i=0;i<=3;i++)
{
	printf("i value => %d\n",i);
	for (j=0;j<=3;j++)
	{
	printf("j value=>%d \tx[%d] value=>%d\n",j,j,x[j]);
	y=j+x[j];
	sum=sum+y;
	}
}
printf("Y value , sum  : %d\t%d\n",y,sum);

}



