/*

In some cases, where m and n are small for for loops, parallelization doesn't optimize. So we check using an if statement in the declaration
|| #pragma omp parallel for if(m>100) || -> Will parallelize only if m > 100

*/

#include<stdio.h>
#include<omp.h>
