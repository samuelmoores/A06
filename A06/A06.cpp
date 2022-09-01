//Sam Moores
//ID: 1864262
//Project 6
//This program extends the container class program
//Added is a base class sequence and all classes have
//been put in separate compilation files

#include <iostream>
#include "Container.h"
#include "Sequence.h"

int main()
{
	CS52::Container m(5, 3);
	CS52::Container n(3, 0);
	CS52::Container o;

	n[0] = 55;
	n[1] = 100;
	n[2] = 500;

	o = n - m;

	std::cout << "Test overloaded - operator\n";
	std::cout << "m = [3,3,3,3,3], n = [55 ,100 ,500]\n";
	std::cout << "o = n - m = [" << o << "]\n";

	const int SIZE = 2;
	Sequence* sequence[2];

	sequence[0] = new CS52::Container(5, 11);
	sequence[1] = new CS52::Container(3, 7);

	std::cout << "\nTest Polymorphism\n";

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "sequence[" << i << "] is a " << sequence[i]->type()
			<< ": " << *(dynamic_cast<CS52::Container*>(sequence[i])) << " "
			<< "\n";
	}

	for (int i = 0; i < 2; i++)
	{
		delete sequence[i];
	}

}

