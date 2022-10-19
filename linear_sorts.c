#include <stdlib.h> /* malloc */
#include <assert.h> /* assert */
#include <string.h> /* memcpy */
#include "linear_sorts.h"


typedef struct min_max
{
	int min_value;
	int max_value;
}min_max_ty;


void CountingSort(int *arr , size_t size);
void RadixSort(int *arr , size_t size);

static min_max_ty MinAndMax(int *arr , size_t size);
static void InitialArr(int *arr , size_t size);
static void CountingSortByDigit(int *arr , size_t size , int divide);
static int Pow(int x , int y);
static int MaxDigits(int *arr , size_t size);
static void	FillCountArray(int *count_arr , int *arr ,size_t size ,int index_fix);
static void FillSortedElements(int *count_arr , int *arr ,
									size_t range , int index_fix);
									




void CountingSort(int *arr , size_t size)
{
	min_max_ty min_max = {0};
	size_t range = 0;
	int *count_arr = NULL;
	int index_fix = 0;
	assert(NULL != arr);
	
	min_max = MinAndMax(arr , size);
	range = min_max.max_value - min_max.min_value + 1;
	count_arr = (int*)malloc(sizeof(int) * range);
	InitialArr(count_arr , range);	
	index_fix = -min_max.min_value;
		
	FillCountArray(count_arr , arr , size , index_fix);
	
	FillSortedElements(count_arr , arr , range , index_fix);
	free(count_arr);
}


void RadixSort(int *arr , size_t size)
{
	int max_digits = MaxDigits(arr , size); /*the max num of digits in element*/
	int i = 0;
	
	for( ; i < max_digits ; ++i)
	{
		CountingSortByDigit(arr , size , Pow(10 , i));
	}	
}



/*================= static functions =================*/


static min_max_ty MinAndMax(int *arr , size_t size)
{
	size_t i = 1;
	min_max_ty min_max = {0};	
	assert(NULL != arr);
	
	min_max.min_value = arr[0];
	min_max.max_value = arr[0];
		
	for( ; i < size ; ++i)
	{
		if(min_max.min_value > arr[i])
		{
			min_max.min_value = arr[i];
		}
		if(min_max.max_value < arr[i])
		{
			min_max.max_value = arr[i];
		}
	}
	
	return min_max;
}


static void InitialArr(int *arr , size_t size)
{
	size_t i  = 0;
	assert(NULL != arr);
	
	for( ; i < size ; ++i)
	{
		arr[i] = 0;
	}
} 

static void CountingSortByDigit(int *arr , size_t size , int divide)
{
	const size_t range = 10;
	int count_arr[10] = {0};
	int *sort_arr = (int*)malloc(sizeof(int) * size);
	size_t i = 0;
	assert(NULL != arr);
	
	
	for( ; i < size ; ++i)
	{
		count_arr[(arr[i] / divide) % 10] += 1;
	}
	
	for(i = 0 ; i < range - 1 ; ++i)
	{
		count_arr[i + 1] += count_arr[i]; 
	}

	for(i = size - 1 ; (int)i >= 0 ; --i)
	{
		sort_arr[count_arr[(arr[i] / divide) % 10] - 1] = arr[i];
		--count_arr[(arr[i] / divide) % 10];
	}
	memcpy(arr , sort_arr , size * sizeof(int));

	free(sort_arr);

}


static int Pow(int x , int y)
{
	int i = 0;
	int result = 1;
	
	for( ; i < y ; ++i)
	{
		result *= x;
	}
	return result;
}


static int MaxDigits(int *arr , size_t size)
{
	size_t i = 0;
	int counter = 0;
	int max = arr[0];
	assert(NULL != arr);
	
	for( ; i < size ; ++i)
	{
		if(max < arr[i])
		{
			max = arr[i];
		}	
	}
	
	while(0 < max)
	{
		++counter;
		max /= 10;
	}
	
	return counter;
}

static void	FillCountArray(int *count_arr , int *arr ,size_t size ,int index_fix)
{
	size_t i = 0;
	assert(NULL !=count_arr);
	assert(NULL != arr);
	
	for(; i < size ; ++i)
	{
		++count_arr[arr[i] + index_fix];
	}
}

static void FillSortedElements(int *count_arr , int *arr ,
									size_t range , int index_fix)
{
	int insert = 0;
	size_t i = 0;
	int j = 0;
	assert(NULL != count_arr);
	assert(NULL != arr);
	
	for(i = 0 ; i < range ; ++i)
	{
		for(j = 0 ; j < count_arr[i] ; ++j)
		{
			arr[insert++] = i - index_fix;	
		}
	}	
}




