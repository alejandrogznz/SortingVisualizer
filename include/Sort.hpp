# ifndef SORTINGVISUALIZER_SORT_H
# define SORTINGVISUALIZER_SORT_H

# include <SFML/Graphics.hpp>
# include <iostream>
# include <vector>
# include <stdlib.h>

# define DEF_SIZE 1000

class Sort
{

protected:

	sf::RenderWindow window;

	std::vector<sf::RectangleShape*> rectangles;

	std::vector<int> vals;

	unsigned int size;

public:

	Sort();

	void run();


protected:

	virtual void initializeWindow();

	virtual void sort(int min, unsigned int max) = 0;

	virtual void swapAndDraw(unsigned int a, unsigned int b);

private:

	void randomizeArray();

	void swapValue(unsigned int a, unsigned int b);

	void redrawAll();

};

# endif // SORTINGVISUALIZER_SORT_H