#pragma once
#include <iostream>
#include "Sequence.h"

namespace CS52 
{

	class Container : public Sequence
	{

		public:

			Container();
			Container(int size, int initial_value);
			Container(const Container& c);
			~Container();

			void info(Container& c);

			int* Data();

			int getSize() override;

			int& at(int i);

			int& back();

			int& front();

			int getCapacity() override;

			void clear();

			bool empty();

			void pop_back();

			void push_back(int element);

			int find(int key);

			int& operator[](int i);

			Container& operator=(const Container&);

			friend std::ostream& operator <<(std::ostream& o, Container& c);

			std::string type() const override;

			Container operator -(const Container& rhs);

		private:
			int size = 0;
			int capacity = 0;
			int* data = nullptr;

	};//Container

}//namespace


