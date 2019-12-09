# include "./../include/QuickSort.hpp"

using namespace std;

QuickSort::QuickSort()
	:window(sf::VideoMode(1600,400), "QuickSort"), size(DEF_SIZE), rectangles(), vals(DEF_SIZE) 
{
	for (int i = 0; i < size; ++i)
	{
		vals[i] = i + 1;
	}

	initializeWindow();
}

QuickSort::QuickSort(unsigned int x, unsigned int y, unsigned int size)
	:window(sf::VideoMode(x,y), "QuickSort"), size(size), vals(size)
{
	//cout << "Hello QuickSort" << endl;
}

void QuickSort::run()
{
	bool sort_ran = false;
	while (window.isOpen())
	{
		sf::Event event;
		while(window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (!sort_ran)
			{
				sort(0, size - 1);
				sort_ran = true;
			}
		}
	}
}

void QuickSort::initializeWindow()
{

	sf::RectangleShape * rect = nullptr;
	float x_delta = window.getSize().x/(float)size;
	float y_delta = window.getSize().y/(float)size;
	unsigned int x_dim = window.getSize().x;
	unsigned int y_dim = window.getSize().y;

	cout << "X: " << window.getSize().x << " Y: " << window.getSize().y << endl;
	cout << "X: " << x_delta << " Y: " << y_delta << endl;

	
	// Initialize the rectangles that will be displayed 
	// in the SFML window
	for (int i = 0; i < size; ++i)
	{
		rect = new sf::RectangleShape(sf::Vector2f(x_delta - 1, y_delta * (i + 1)));
		rect->move(x_delta * i, y_dim - ((i + 1) * y_delta));
		rectangles.push_back(rect);
	}

	randomizeArray();
}

void QuickSort::randomizeArray()
{
	int r = 0;
	for (int i = 0; i < size; ++i)
	{
		r = rand() % size;
		if (r == i){
			continue;
		}
		swapValue(i, r);
	}
}

void QuickSort::sort(unsigned int min, unsigned int max)
{
	if (max - min < 1000)
	{
		for (int i = max; i > 0; --i)
		{
			for (int j = min; j + 1 <= i; ++j)
			{
				if (vals[j] > vals[j + 1])
					swapAndDraw(j, j + 1);
			}
		}
		return;
	}

	unsigned int median = medianOfThrees(min, (max + min)/2 + 1, max);
	unsigned int midpoint = partition(min, max, median);
	cout << "M: " << min << " Mi: " << midpoint << " H:" << max << endl; 
	sort(min, midpoint - 1);
	sort(midpoint + 1, max);
	return;
}

unsigned int QuickSort::medianOfThrees(unsigned int min, unsigned int mid, unsigned int max)
{
	if (vals[mid] > vals[max])
		swapAndDraw(mid, max);
	if (vals[min] > vals[mid])
		swapAndDraw(min, mid);
	if (vals[max] > vals[mid])
		swapAndDraw(max, mid);

	return vals[max];
}

unsigned int QuickSort::partition(unsigned int min, unsigned int max, unsigned int median)
{
	int pivot = min;
	for (int i = pivot; i < max; ++i)
	{
		if (vals[i] < median)
		{
			swapAndDraw(pivot, i);
			++pivot;
		}
	}

	swapAndDraw(pivot, max);
	return pivot;
}

void QuickSort::swapValue(unsigned int a, unsigned int b)
{
	// Swap vals values
	int temp = vals[a];
	vals[a] = vals[b];
	vals[b] = temp;

	sf::Vector2f position_a = rectangles[a]->getPosition();
	sf::Vector2f position_b = rectangles[b]->getPosition();
	rectangles[a]->setPosition(sf::Vector2f(position_b.x, position_a.y));
	rectangles[b]->setPosition(sf::Vector2f(position_a.x, position_b.y));
}


void QuickSort::swapAndDraw(unsigned int a, unsigned int b)
{
	swapValue(a, b);

	redrawAll();
}


void QuickSort::redrawAll()
{
	window.clear();
	for (auto shape : rectangles)
	{
		window.draw(*shape);
	}
	window.display();
}