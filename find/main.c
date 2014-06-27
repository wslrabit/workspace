#include <stdio.h>
int find(int key,int array[],int low,int high)
{
		int mid ;
		while(high>=low){
			// priority of operation '+' is higher then '>>'
			mid = low+((high-low)>>1);
			//mid = (low+high)/2;
			if(array[mid]>key)
				high = mid-1;
			else if(array[mid]<key)
				low = mid+1;
			else
				return mid;
		}
		return (int)-1;
}

int main(int argc, char *argv[])
{
	printf("Hello C-Free! %d\n",0>>1);
	int array[]={
		1,2,3,5,7,8,11
	};
	printf("find %ud in array\n",find(3,array,0,6));
	return 0;
}
