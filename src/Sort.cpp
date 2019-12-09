# include "./../include/Sort.hpp"

Sort::Sort()
	:window(sf::VideoMode(1600,400), "QuickSort"), size(DEF_SIZE), rectangles(), vals(DEF_SIZE) 
{

}

void Sort::run()
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


void Sort::initializeWindow()
{

	sf::RectangleShape * rect = nullptr;
	float x_delta = window.getSize().x/(float)size;
	float y_delta = window.getSize().y/(float)size;
	unsigned int x_dim = window.getSize().x;
	unsigned int y_dim = window.getSize().y;
	
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

void Sort::randomizeArray()
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

void Sort::swapValue(unsigned int a, unsigned int b)
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


void Sort::swapAndDraw(unsigned int a, unsigned int b)
{
	swapValue(a, b);

	redrawAll();
}


void Sort::redrawAll()
{
	window.clear();
	for (auto shape : rectangles)
	{
		window.draw(*shape);
	}
	window.display();
}
