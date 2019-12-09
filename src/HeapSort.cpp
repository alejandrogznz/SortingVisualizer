# include "./../include/HeapSort.hpp"

HeapSort::HeapSort()
	:Sort()
{
	for (int i = 0; i < size; ++i)
	{
		vals[i] = i + 1;
	}

	initializeWindow();
}



