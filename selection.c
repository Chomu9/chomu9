#include<stdio.h>
#include<time.h>
#include<math.h>

void selectsort(int n,int array[])
{
	int i,j,temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
	for(j=i+1;j<n;j++)
	{
		if(array[j]<array[min])
		{
		min=j;
		}
	}
	if(i!=min)
	{
		temp=array[min];
		array[min]=array[i];
		array[i]=temp;
	
	}
	}
		printf("Sorted array\n");
		for(i=0;i<n;i++)
		printf("%d\n",array[i]);
}

int main()
{
	clock_t start,end;
	double time;
	int i,n,arr[200];
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	start=clock();
	selectsort(n,arr);
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%lf",time);
	return 0;
}
	
