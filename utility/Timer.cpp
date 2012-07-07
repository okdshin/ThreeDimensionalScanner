#ifdef UNIT_TEST
#include "Timer.h"
#include <iostream>

using namespace utl;

int main(int argc, char* argv[])
{
	auto timer = Timer();
	unsigned int sum = 0;
	for(unsigned int i = 0; i < 100000000; i++)
	{
		sum += i;
	}
	std::cout << sum << std::endl;
	timer("time is");

    return 0;
}

#endif
