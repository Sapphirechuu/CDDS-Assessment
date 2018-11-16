#include "Merge.h"
#include <iostream>

int main()
{
	int arr[] = {82, 5, 4, 69, 7, 8};
	MergeSort(arr, 0, 5);
	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << std::endl;
	}
	return 0;
}