#ifndef __ILRD_OL_127_128_LINEAR_SORT_H__
#define __ILRD_OL_127_128_LINEAR_SORT_H__

#include <stddef.h> /* size_t */

/*
Description : the CountingSort() function sort array of elements.
it sorts the elements of an array by counting the number of
occurrences of each unique element
in the array.

return value : void
time cpmlexity : O(n)
*/
void CountingSort(int *arr , size_t size);

/*
Description : the RadixSort() function sort array of elements.
The function sorts the elements in an array with the help of
comparing their digits.

return value : pointer to new sorted array
time complexity : O(n*k) , where n is the number of elements
and k is the maximum num of digits in one element
*/
void RadixSort(int *arr , size_t size);

#endif /* __ILRD_OL_127_128_LINEAR_SORT_H__ */


















