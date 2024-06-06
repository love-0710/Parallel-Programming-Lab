#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void merge_sort(int arr[],int start,int end){
	if(start<end){
		int mid=(start+end)/2;
		merge_sort(arr,start,mid);
		merge_sort(arr,mid+1,end);
		 MERGE(arr,start,mid,end);

	}
}
void MERGE(int arr[],int l, int m, int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	
	int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++){
		R[j]=arr[m+1+j];
	}
	i=0;j=0;k=l;
	
	while(i<n1 && j<n2){
		if(L[i]<=R[j]){
			arr[k]=L[i];
			i++;
			}
		else{
			arr[k]=R[j];
			j++;
			}
			k++;
	}
	while(i<n1){
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=R[j];
		j++;
		k++;
		}
	}


int main()
{
        int l=1000000,i=0;
        char x[10];
        int * arr=(int*)malloc(l*sizeof(int));
        FILE *f=fopen("numbers.txt","r");
        while(feof(f)==0){
                fscanf(f, "%s" ,x);
                arr[i]=atoi(x);
                i++;
        }
        fclose(f);
        f=fopen("numbers.txt","w");
	double start,end;
	start=omp_get_wtime();
        merge_sort(arr,0,l);
	end=omp_get_wtime();
        for(i=0; i<l; i++){
        fprintf(f, " %d " ,arr[i]);
        }
	printf("EXECUTION TIME = %2f\n",end-start);
}


