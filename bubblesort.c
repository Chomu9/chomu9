#include<stdio.h>
#include<time.h>
#include<math.h>

void bubblesort(int n,int array[])
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
	for(j=0;j<n-i-1;j++)
	{
		if(array[j]>array[j+1])
		{
		temp=array[j];
		array[j]=array[j+1];
		array[j+1]=temp;
		}
	}
	}
		printf("Sorted array\n");
		for(i=0;i<n;i++)
		printf("%d\n",array[i]);
}
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
	clock_t start1,start2,end1,end2;
	double time1,time2;
	int i,n,arr1[200],arr2[200];
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Generating random elements\n");
	for(i=0;i<n;i++){
	arr1[i]=rand()%100;
	arr2[i]=arr1[i];
	printf("%d\n",arr1[i]);}
	start1=clock();
	bubblesort(n,arr1);
	end1=clock();
	time1=(double)(end1-start1)/CLOCKS_PER_SEC;
	printf("Bubble sort:%lf\n",time1);
	
	start2=clock();
	selectsort(n,arr2);
	end2=clock();
	
	time2=(double)(end2-start2)/CLOCKS_PER_SEC;
	printf("Selection sort:%lf\n",time2);
	
	return 0;

}
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
