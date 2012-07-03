#ifdef UNIT_TEST
#include "Color.h"
#include <iostream>

using namespace mg;

int main(int argc, char* argv[])
{
	common::Vector<int, 5> v5i;
	v5i(0) = 1;
	v5i(1) = 2;
	v5i(2) = 3;
	v5i(3) = 4;
	v5i(4) = 5;
	const auto color5i = Color<int, 5>(v5i);
	std::cout << color5i << std::endl;
	
	common::Vector<int, 5> v5i2;
	v5i(0) = 2;
	v5i(1) = 2;
	v5i(2) = 3;
	v5i(3) = 4;
	v5i(4) = 5;
	const auto color5i2 = Color<int, 5>(v5i2);
	std::cout << color5i2 << std::endl;
	if(color5i != color5i2)
	{
		std::cout << "1 2" << std::endl;
	}
	if(color5i == color5i)
	{
		std::cout << "1 1" << std::endl;
	}
    return 0;
}

#endif
