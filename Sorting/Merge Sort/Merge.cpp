#include "Merge.h"
#include <iostream>

void Merge(int * arr, size_t p, size_t q, size_t r)
{
	size_t leftEnd = q - p + 1;
	size_t rightEnd = r - q;
	int * L = new int[leftEnd];
	int * R = new int[rightEnd];

	for (size_t i = 0; i < leftEnd; ++i)
	{
		L[i] = arr[p + i];
	}

	for (size_t j = 0; j < rightEnd; ++j)
	{
		R[j] = arr[q + j + 1];
	}
	int i = 0;
	int j = 0;

	

	for (size_t k = p; k <= r; ++k)
	{
		if ((j >= rightEnd) || ((i < leftEnd) && L[i] <= R[j]))
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
	}
	delete[] L;
	delete[] R;
}

void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
		size_t q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}
