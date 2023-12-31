#include <stdio.h>

void swap(int* a, int* b)
{

    int temp = *a;
	*a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
  
    int largest = i;

    int left = 2 * i + 1;

    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])

        largest = left;

   
    if (right < N && arr[right] > arr[largest])

        largest = right;


if (largest != i) {

        swap(&arr[i], &arr[largest]);


        heapify(arr, N, largest);
    }
}
