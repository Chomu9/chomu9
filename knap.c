#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

	if (n == 0 || W == 0)
		return 0;

	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	else
		return max(val[n - 1]+ knapSack(W - wt[n - 1], wt, val, n - 1),knapSack(W, wt, val, n - 1));
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
	printf("Enter the value of each object\n");
	for(int i=0;i<n;i++)
	scanf("%d",&val[i]);
	knapSack(W,wt,val,n);
	printf("%d", knapSack(W, wt, val, n));
	
	return 0;
	}
