
main: main.o QuickSort.o Sort.o 
	g++ main.o QuickSort.o  Sort.o -o main -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -c main.cpp

QuickSort.o: ./include/QuickSort.hpp ./src/QuickSort.cpp 
	g++ -c ./src/QuickSort.cpp

Sort.o: ./include/Sort.hpp ./src/QuickSort.cpp
	g++ -c ./src/Sort.cpp

HeapSort.o: ./include/HeapSort.hpp ./src/HeapSort.cpp
	g++ -c ./src/HeapSort.cpp

clean:
	rm -f *.o
