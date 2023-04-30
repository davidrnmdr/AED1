// EP 05 - Selection Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//swap two variables
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
           if(min_idx != i)
            swap(&arr[min_idx], &arr[i]);
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

	selectionSort(d, 20000);
	end = clock();

	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("The execution time was : %f", duration);
	
	return 0;
}