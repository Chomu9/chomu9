#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}

int knapsack(int W,int wt[],int val[],int n)
{
	int i,w;
	int k[n+1][W+1];
	for(i=0;i<=n;i++)
	{
		for(w=0;w<=W;w++)
		{
		if(i==0||w==0)
		k[i][w]=0;
	
		else if(wt[i-1]<=w)
		k[i][w]=max(val[i-1]+k[i-1][w-wt[i-1]],k[i-1][w]);
	
		else
		k[i][w]=k[i-1][w];
	}
	}
	return k[n][W];
	}

int main()
{
	int W, wt[25],val[25],n;
	printf("Enter no of objects\n");
	scanf("%d",&n);
	printf("Enter the max weight\n");
	scanf("%d",&W);
	printf("Enter the weight of each object\n");
	for(int i=0;i<n;i++)
	scanf("%d",&wt[i]);
	printf("\n");
	printf("Enter the value of each object\n");
	for(int i=0;i<n;i++)
	scanf("%d",&val[i]);
	knapsack(W,wt,val,n);
	printf("%d", knapsack(W, wt, val, n));
	
	return 0;
}
