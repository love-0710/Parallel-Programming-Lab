#include<stdio.h>
#include<omp.h>
#define ASIZE 10000
int main(){
	double start,end;
	int a[ASIZE],i,tid,numt,psum,sum=0;
	for(i=0;i<10000;i++)
		a[i]=1;
		start = omp_get_wtime();
{
	int from,to,psum=0;
	tid = omp_get_thread_num();
	numt=omp_get_num_threads();
	from=(ASIZE/numt)*tid;
	to=(ASIZE/numt)*(tid+1)-1;
		if(tid==numt-1)
			to = ASIZE - 1;
		for(i=from;i<=to;i++)
			psum=psum+a[i];
		{
			sum=sum+psum;
		}
}
	end = omp_get_wtime();
	printf("Final sum = %d",sum);
	printf("execution time = %2f",end-start);
	return 0;
}
