// EP 05 - Quick Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swaps two variables
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
//partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
     
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
//quick sorts an array from index low to index high
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
         
        // pi is partitioning index, arr[p]
        // is now at right place
        int pi = partition(arr, low, high);
         
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){

clock_t start, end;
	start = clock();

// 	int a[5000];
//   for(int i=0; i< 5000; i++){
//     a[i] = rand()%1000;
//   }

//   int b[10000];
//   for(int i=0; i< 10000; i++){
//     b[i] = rand()%1000;
//   }

//   int c[15000];
//   for(int i=0; i< 15000; i++){
//     c[i] = rand()%1000;
//   }

  int d[20000];
  for(int i=0; i< 20000; i++){
    d[i] = rand()%1000;
  }

	quickSort(d, 0, 19999);

	end = clock();

	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("The execution time was : %f", duration);
	
	return 0;
}