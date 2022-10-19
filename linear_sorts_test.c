#include <assert.h> /* assert */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* malloc */
#include "linear_sorts.h"

void CountingSortTest(void);
void RadixSortTest(void);

int main(void)
{
	CountingSortTest();
	RadixSortTest();

	return 0;
}


void CountingSortTest(void)
{
	int arr[5000] = {0};
	int i = -2500;
	for( ; i < 2500 ; ++i)
	{
		arr[i + 2500] = i % 31;
	}	
	
	CountingSort(arr , 5000);
	
	for(i = 0 ; i < 4999 ; ++i)
	{
		assert(arr[i] <= arr[i + 1]);
	}	
}


void RadixSortTest(void)
{
	int *arr = (int*)malloc(4 * 5000);
	int i = 0;
	for( ; i < 5000 ; ++i)
	{
		arr[i] = i % 18;
	}	

	RadixSort(arr , 5000);
	
	for(i = 0 ; i < 4999 ; ++i)
	{
		assert(arr[i] <= arr[i + 1]);
	}
	free(arr);	
}






































