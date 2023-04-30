// EP 05 - Heap Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap two variables
void swap(int* a, int* b)
{ 
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// heapify a tree of size n rooted in i
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
 
//takes an array and heap sort it
void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    // heap sort
    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        
        heapify(arr, i, 0);
    }
}

int main(){

clock_t start, end;
	start = clock();

	int a[5000];
  for(int i=0; i< 5000; i++){
    a[i] = rand()%1000;
  }

//   int b[10000];
//   for(int i=0; i< 10000; i++){
//     b[i] = rand()%1000;
//   }

//   int c[15000];
//   for(int i=0; i< 15000; i++){
//     c[i] = rand()%1000;
//   }

//   int d[20000];
//   for(int i=0; i< 20000; i++){
//     d[i] = rand()%1000;
//   }

	heapSort(a, 5000);
	end = clock();

	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("The execution time was : %f", duration);
	
	return 0;
}