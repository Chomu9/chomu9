#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int u){
	int n1 = m - l + 1;
	int n2 = u - m;
	
	int left[n1];
	int right[n2];
	
	for(int i = 0; i < n1; i++)
		left[i] = arr[l + i];
	for(int i = 0; i < n2; i++)
		right[i] = arr[m + 1 + i];
	
	int i = 0, j = 0, k = l;
	while(i < n1 && j < n2){
		if(left[i] <= right[j])
			arr[k++] = left[i++];
		else if(left[i] > right[j])
			arr[k++] = right[j++];
	}
	while(i < n1)
		arr[k++] = left[i++];
	while(j < n2)
		arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int u){
	if(l < u){
		int m = l + (u - l)/2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, u);
		merge(arr, l, m, u);
	}
}

int main(){
	printf("Enter the size of the array:\n");
	int n;
	scanf("%d", &n);
	
	int arr[n];
	
	//printf("Enter the range of random values to be generated:\n");
	//int l = 0, u = 500;
	//scanf("%d", &l);
	//scanf("%d", &u);
	
	for(int i = 0; i < n; i++)
		arr[i] = 1000+10*(3.14*i);
		
	clock_t s, e;	
	
	s = clock();
	mergeSort(arr, 0, n - 1);
	e = clock(); 
	
	double time = ((double)(e-s))/CLOCKS_PER_SEC;
	
	printf("Time taken: %lfs\n", time);
	
	//for(int i = 0; i < n; i++)
		//printf("%d ", arr[i]);
	
}
