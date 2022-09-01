#pragma once

class Sequence 
{
	public: 
		virtual int getSize() = 0;
		virtual int getCapacity() = 0;
		virtual std::string type() const = 0;
		virtual ~Sequence() {};
};
