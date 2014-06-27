#include <stdio.h>
void insert(int array[],int size){
	int i=1,j=0;
	for(;i<size;i++){
		if(array[i]<array[i-1]){
			int temp = array[i];
			for(j=i-1;j>=0;j--)
				if(array[j]>temp)
					array[j+1]=array[j];
				else
					break;
			array[j+1]=temp;
		}
	}
}
void select(int array[],int size){
	int i,j,k;
	for(i=0;i<size;i++){
		int min = array[i];
		k = i;
		for(j=i+1;j<size;j++){
			if(array[j]<min){
				min=array[j];
				k=j;
			}
		}
		if(k!=i){
			array[k]=array[i];
			array[i]=min;
		}
	}
}

void shell(int a[], int size){
	int step = 1;
	while((step*3)+1<size)
		step = step*3+1;
	while(step>0){
		int i=0;
		for(;i<step;++i){
			int j=i+step;
			for(;j<size;j+=step){
				int temp = a[j];
				int k = j-step;
				for(;k>=0;k-=step){
					if(a[k]>temp)
						a[k+step]=a[k];
					else
						break;
				}		
				a[k+step]=temp;
			}
		}
		step=(step-1)/3;
		printf("step:%d\n",step);
	}
}

int main(int argc, char *argv[])
{
	int a[]={
		3,4,2,7,9,4,6
	};
	int i =0;
	shell(a,sizeof(a)/sizeof(int));
	for(;i<7;i++)
		printf("i:%d,a[i]:%d\n",i,a[i]);
	return 0;
}
