#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

void bubblesort(int* arr,int l){
	for(int i=0;i<l;i++){
		for(int j=0;j<l-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				}
		}
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
	f=fopen("bubbledataset.txt","w");
        double start,end;
        start = omp_get_wtime();
        bubblesort(arr,l);
        end = omp_get_wtime();
        fprintf(f,"EXECUTION TIME = %2f\n",end-start);
        for(i=0; i<l; i++){
         fprintf(f," %d " ,arr[i]);
        }
	fclose(f);
	return 0;
}


