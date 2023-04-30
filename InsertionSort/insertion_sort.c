// EP 05 - Insertion Sort
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* takes an array ant Insertion Sort it*/
void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int main()
{

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

	insertionSort(a, 5000);
	end = clock();

	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("The execution time was : %f", duration);
	
	return 0;
}
