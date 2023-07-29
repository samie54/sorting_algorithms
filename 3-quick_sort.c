
#include "sort.h"

/**
 * partition - array partition.
 * @array: sorted array.
 * @first: firstly positioned.
 * @last: lastly positioned.
 * @size: array size.
 * Return: int pivot indexx.
 */

int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * qs - array of integers sorted recursively.
 * @array: sorted array.
 * @first: firstly positioned.
 * @last: lastly positioned.
 * @size: array size.
 */
void qs(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		qs(array, first, pivot - 1, size);
		qs(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - array of integers sorted.
 * in ascending order using quick sort algorithm.
 * @array: sorted array.
 * @size: size of array.
 */
void quick_sort(int *array, size_t size)
{
	qs(array, 0, size - 1, size);
}
