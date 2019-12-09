# ifndef SORTINGVISUALIZER_QUICKSORT_H
# define SORTINGVISUALIZER_QUICKSORT_H

# include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>
# include <stdlib.h>

# include "Sort.hpp"

# define DEF_SIZE 1000

class QuickSort
{

	sf::RenderWindow window;

	std::vector<sf::RectangleShape*> rectangles;
	
	std::vector<int> vals;

	unsigned int size;

public:

	QuickSort();

	QuickSort(unsigned int x, unsigned int y, unsigned int size);

	void run();

private:

	void initializeWindow();

	void randomizeArray();

	void sort(unsigned int min, unsigned int max);

	unsigned int medianOfThrees(unsigned int min, unsigned int mid, unsigned int max);

	unsigned int partition(unsigned int min, unsigned int max, unsigned int median);

	void swapValue(unsigned int a, unsigned int b);

	void swapAndDraw(unsigned int a, unsigned int b);

	void redrawAll();
};

# endif // SORTINGVISUALIZER_QUICKSORT_H