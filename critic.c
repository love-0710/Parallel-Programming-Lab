#include<stdio.h>
int main(){
int i,sum=0,a[10000];
for(i=0;i<10000;i++)
	a[i]=1;
for(i=0;i<10000;i++)
	sum = sum+a[i];
printf("sum of array elements = %d', sum);
return 0;
}
