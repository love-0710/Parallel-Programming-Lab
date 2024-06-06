#include<stdio.h>
#include<stdlib.h>
int main()
{
        int l=4000000;
        for(int i=0;i<l;i++)
        {
                printf(" %ld ",random()%100000);
        }
}

