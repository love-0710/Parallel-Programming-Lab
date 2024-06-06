#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void swap(int* a,int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

int partition(int arr[],int low,int high){
        int pivot = arr[low];
        int i = low;
        int j = high;
        while(i<j){
		while(arr[i] <= pivot && i <= high-1){
			i++;
		}
		while(arr[j] > pivot && j >= low+1){
			j--;
		}
		if(i<j){
			swap(&arr[i],&arr[j]);
			}
		}
	swap(&arr[low],&arr[j]);
	return j;
}
void quick_sort(int arr[],int low,int high){
        if(low<high){
                int partitionIndex = partition(arr,low,high);             
                quick_sort(arr,low,partitionIndex-1);
                quick_sort(arr,partitionIndex+1,high);

        }
}

int main()
{
        long int l=4000000,i=0;
        char x[10];
        int * arr=(int*)malloc(l*sizeof(int));
        FILE *f=fopen("numbers.txt","r");
        while(feof(f)==0){
                fscanf(f, "%s" ,x);
                arr[i]=atoi(x);
                i++;
        }
        fclose(f);
        double start,end;
        start=omp_get_wtime();
        quick_sort(arr,0,l);
        end=omp_get_wtime();
	printf("EXECUTION TIME = %2f\n",end-start);
        for(i=0; i<l; i++){
	 printf(" %d " ,arr[i]);
        }
}

