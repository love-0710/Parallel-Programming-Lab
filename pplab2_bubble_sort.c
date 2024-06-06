#include<stdio.h>
#include<stdlib.h>
void bubblesort(int * arr,int l)
{
	for(int i=0; i<l; i++){
		for(int j=0; j<l-i-1; j++){
			if(arr[j]<arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				}
			}
		}
}	
int main()
{
	int l=10000,i=0;
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
	bubblesort(arr,l);
	for(i=0; i<l; i++){
	fprintf(f, " %d " ,arr[i]);
	}
}

