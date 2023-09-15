#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int table[1000],flag;
void shifttable(char p[])
{
	int m,i,j;
	m=strlen(p);
	for (i=0;i<1000;i++)
	table[i]=m;
	for (j=0;j<=m-2;j++)
	table[p[j]]=m-1-j;
}

int horsepool(char p[],char t[])
{
	int m,n,i,j,k;
	shifttable(p);
	m=strlen(p);
	n=strlen(t);
	i=m-1;
	flag=0;

	while (i<=n-1)
	{
		k=0;
	while ((k<=m-1) && t[i-k]==p[m-1-k])
	k++;
	if (k==m){
	printf("\nPattern found at position %d",i-m+2);
	flag=1;
	i=i+table[t[i]];
	}
	else
	i=i+table[t[i]];}
	return -1;
}
int main()
{
	char str[100],ptr[100];
	int res;
	printf("Enter the text:");

	gets(str);
	printf("Enter pattern:");

	gets(ptr);
	res=horsepool(ptr,str);
	if (res==-1 && flag==0)
	printf("Not found");
}
