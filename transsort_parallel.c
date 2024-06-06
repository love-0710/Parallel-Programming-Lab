#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void swap(int* a,int*b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

void odd_even_sort(int* arr,int l){
        int sort=0;
        while(!sort){
                sort = 1;
		#pragma omp parallel sections
		{
			#pragma omp section
			{
                for(int i=0;i<l-1;i=i+2){
                        if(arr[i]>arr[i+1]){
                                swap(&arr[i],&arr[i+1]);
                                sort=0;
                                }
                }
		}
	#pragma omp section
	{
              for(int i=1;i<l-1;i=i+2){
                        if(arr[i]>arr[i+1]){
                                swap(&arr[i],&arr[i+1]);
                                sort=0;
                                }
                }
	}
	}
        }
}


int main()
{
        long int l=100000,i=0;
        char x[10];
        int * arr=(int*)malloc(l*sizeof(int));
        FILE *f=fopen("numbers.txt","r");
        while(feof(f)==0){
                fscanf(f, "%s" ,x);
                arr[i]=atoi(x);
                i++;
        }
        fclose(f);
        f=fopen("oddparalleldataset.txt","w");
        double start,end;
        start=omp_get_wtime();
        odd_even_sort(arr,l);
	 end=omp_get_wtime();
        printf("EXECUTION TIME of parallel odd_even transposition sort= %2f seconds\n",end-start);
        for(i=0; i<l; i++){
         fprintf(f," %d " ,arr[i]);
        }
        fclose(f);
        return 0;
}

