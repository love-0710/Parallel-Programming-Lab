#include<stdio.h>
#include<stdlib.h>
int main()
{
	int l=100000;
	for(int i=0;i<l;i++)
	{
		printf(" %ld ",random()%10000);
	}
}
