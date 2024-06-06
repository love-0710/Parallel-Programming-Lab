#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void linearsearch(int * arr,int l,int key){
	int i;
     for(i=0; i<l; i++)
	{
		if(arr[i]==key){
			printf("ELEMENT FOUND AT INDEX %d\n", i);
			break;
			}
	}
if(i==l){printf("element not found\n");}
}

int main()
{
        double start,end;
        int l=10000,i=0,key;
        char x[10];
        int * arr=(int*)malloc(l*sizeof(int));
        FILE *f=fopen("numbers.txt","r");
        while(feof(f)==0){
                fscanf(f,"%s",x);
                arr[i]=atoi(x);
                i++;
        }
        fclose(f);
        printf("enter element to be searched\n");
        scanf("%d",&key);
        start = omp_get_wtime();
        linearsearch(arr,l,key);
        end = omp_get_wtime();
         printf("\nexecution time = %f\n",end-start);
        return 0;
}
