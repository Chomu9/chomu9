#include<stdio.h>
#include<stdlib.h>
int W,n,w[10],v[10],x[10],V[10][10];
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int knapsack()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            V[i][j]=0;
            else if(j<w[i])
            V[i][j]=V[i-1][j];
            else
            V[i][j]=max(V[i-1][j],V[i-1][j-w[i]]+v[i]);
            printf("%d \t",V[i][j]);
        }
        printf("\n");
    }
}

void printsoln()
{
    int i,j;
    i=n;
    j=W;
    while(i!=0 && j!=0)
    {
        if(V[i][j]!=V[i-1][j])
        {
        x[i]=1;
        j=j-w[i];
        }
        i--;
    }
    
}
int main()
{
    int i;
    printf("Enter number of objects ");
    scanf("%d",&n);
    printf("Enter knapsack capacity ");
    scanf("%d",&W);
    printf("Enter weights of objects ");
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);
    printf("Enter profits of ojects ");
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    knapsack();
    printsoln();
    printf("Obj\tweight\tprofit\n");
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        printf("%d\t%d\t%d\n",i,w[i],v[i]);
    }
    printf("Max capacity %d",V[n][W]);
    for(i=1;i<=n;i++)
    {
        if(x[i]==1)
        printf("%d object included ",i);
    }
    return 0;
}
