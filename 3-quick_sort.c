#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the Quick
 * Sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1);
	print_array(array, size);
}

/**
 * quicksort_recursive - Recursive helper function for quick_sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 */
void quicksort_recursive(int *array, int low, int high)
{

	if (low < high)
	{
		int pivot = partition(array, low, high);

		quicksort_recursive(array, low, pivot - 1);
		quicksort_recursive(array, pivot + 1, high);
	}
}

/**
 * partition - Partitions the array and places the pivot element in its
 * correct position.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition to be sorted.
 * @high: Ending index of the partition to be sorted.
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high)
{

	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);

	return (i + 1);
}

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
