#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
void binarysearch(int * arr,int l,int key){
     int low=0;
        int up=l-1;
	   while(low<=up)
        {
                int mid;
                mid=((low+up)/2);
                if(key==arr[mid]){
                        printf("element found in dataset at index %d\n",mid);
                        break;
                        }
                else if(low==up){
                        printf("element not found\n");
                        break;
                }
                else if(key>arr[mid])
                {
                        up=mid-1;
                }
                else{
                        low=mid+1;
                }
        }
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
	binarysearch(arr,l,key);
	end = omp_get_wtime();
	 printf("\nexecution time = %f\n",end-start);
	return 0;
}
