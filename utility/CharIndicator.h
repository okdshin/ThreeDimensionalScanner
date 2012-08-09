#pragma once
//CharIndicator:20120718
#include <iostream>
#include <cassert>

namespace utl
{
class CharIndicator
{
public:
	CharIndicator(unsigned int real_limit, unsigned int indicate_limit=20)
		:real_limit(real_limit), 
		indicate_limit(indicate_limit),
		count(0){}


	auto CountAndIndicate() 
	-> unsigned int
	{
		
		++count;
		assert(count <= real_limit);
		std::cout << "\r";
		unsigned int bar_pos = static_cast<unsigned int>(static_cast<double>(indicate_limit)*(static_cast<double>(this->count)/static_cast<double>(this->real_limit)));
		for(unsigned int i = 0; i < bar_pos; i++)
		{
			std::cout << "=";
		}
		for(unsigned int i = 0; i < indicate_limit - bar_pos; i++)
		{
			std::cout << "-";
		}
		std::cout << " " << count << "/" << real_limit;
		if(count == real_limit)
		{
			std::cout << " complete\n";	
		}
		std::cout << std::flush;
		return this->count;
	}

private:
	unsigned int real_limit;
	unsigned int indicate_limit;
	unsigned int count;
};
}

