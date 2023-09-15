#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5000

void merge(int a[],int low,int mid,int high)
{
	int i,j,k,b[MAX];
	i=low;
	j=mid+1;
	k=low;
	while(i<=mid && j<=high)
	{
		if(a[i]<a[j])
		b[k++]=a[i++];
		else
		b[k++]=a[j++];
	}
	
	while(i<=mid)
	{
		b[k++]=a[i++];
	}
	while(j<=high)
	{
		b[k++]=a[j++];
	}
	for(i=low;i<=high;i++)
	a[i]=b[i];
}

void mergesort(int a[],int low,int high)
{	
	if(low<high){
	int mid=(low+high)/2;
	mergesort(a,0,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);}
}

int main()
{
	double time;
	clock_t start,end;
	int i,n;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	int a[n];
	//printf("Enter the elements\n");
	//for(i=0;i<n;i++)
	//scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	a[i]=rand()%100;
	
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	time=(double)(end-start)/CLOCKS_PER_SEC;
	
	//printf("The sorted array\n");
	//for(i=0;i<n;i++)
	//printf("%d\n",a[i]);
	printf("Time taken: %lf\n",time);
	return 0;
}
	
