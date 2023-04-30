// EP 05 - Merge Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//merges two subarrays, from 0 to l, from l to m, and from m to r
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
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

	mergeSort(d, 0, 19999);

	end = clock();

	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("The execution time was : %.10f", duration);
	
	return 0;
}