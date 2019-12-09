# include <iostream>

# include <SFML/Graphics.hpp>

# include "./include/QuickSort.hpp"
//# include "./include/HeapSort.hpp"

# define HEIGHT 500
# define WIDTH 1000


using namespace std;

int main()
{

	QuickSort * qs = new QuickSort();
	qs->run();

	return 0;
}
