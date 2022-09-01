#include <iostream>
#include "Container.h"

namespace CS52
{

Container::Container()
{

}

Container::Container(int size, int initial_value)
{
	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = initial_value;
	}

	this->data = array;

	this->size = size;
	this->capacity = size + 1;


}

Container::Container(const Container& c)
{
	if (this != &c)
	{
		int* array = new int[c.size];

		for (int i = 0; i < c.size; i++)
		{
			array[i] = c.data[i];
		}

		delete[] this->data;

		this->data = array;

		this->size = c.size;
		this->capacity = c.capacity;
	}
}

Container::~Container()
{
	delete[] data;
}

void Container::info(Container& c)
{
	std::cout << "----Info----\n";
	std::cout << "Size: " << c.getSize() << std::endl;
	std::cout << "Capacity: " << c.getCapacity() << std::endl;
	std::cout << "Contents: ";

	for (int i = 0; i < c.getSize(); i++)
	{
		std::cout << c.Data()[i] << " ";
	}


	std::cout << "\n------------\n";
}

int Container::getSize()  
{
	return this->size;
}

int Container::getCapacity()
{
	return this->capacity;
}

int* Container::Data()
{

	return data;

}

int& Container::at(int i)
{
	return data[i];
}

int& Container::back()
{
	return data[size - 1];
}

int& Container::front()
{
	return data[0];
}

void Container::clear()
{
	size = 0;
	delete[]data;
	data = nullptr;
}

bool Container::empty()
{

	if (data == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Container::pop_back()
{
	capacity = size - 1;

	int* tempArray = new int[capacity];

	for (int i = 0; i < capacity; i++)
	{
		tempArray[i] = data[i];
	}

	data = tempArray;

	tempArray = nullptr;
	delete[]tempArray;

	size = size - 1;
}

void Container::push_back(int element)
{
	if (size == capacity)
	{
		capacity = size * 2;
	}
	
	//capacity = size + 1;

	int* tempArray = new int[capacity];

	for (int i = 0; i < capacity; i++)
	{
		if (i == capacity - 1)
		{
			tempArray[i] = element;
		}
		else {
			tempArray[i] = data[i];
		}
	}

	data = tempArray;

	tempArray = nullptr;
	delete[] tempArray;

	size++;

}

int Container::find(int key)
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == key)
		{
			return i;
		}
	}

	std::cout << key << " not found\n";

	return -1;
}

int& Container::operator[](int i)
{
	return data[i];
}

Container& Container::operator=(const Container& c)
{
	if (this != &c)
	{
		int* array = new int[c.size];

		for (int i = 0; i < c.size; i++)
		{
			array[i] = c.data[i];
		}

		delete[] this->data;

		this->data = array;

		this->size = c.size;
		this->capacity = c.capacity;
	}
	return (*this);
}

std::string Container::type() const
{
	std::string type = "CS52::Container";

	return type;
}

Container Container::operator-(const Container& rhs)
{
	
	Container n(this->size, 0);

	if (rhs.size < this->size)
	{
		return rhs;
	}
	else
	{
		for (int i = 0; i < n.getSize(); i++)
		{
			n.data[i] = this->data[i] - rhs.data[i];
		}

		return n;
	}
	
}

std::ostream& operator<<(std::ostream& o, Container& c)
{
	for (int i = 0; i < c.getSize(); i++)
	{
		std::cout << c.Data()[i] << " ";
	}

	return o;
}

}
