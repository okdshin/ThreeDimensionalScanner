#ifdef UNIT_TEST
#include "Color4.h"
#include <iostream>

using namespace mg;

int main(int argc, char* argv[])
{
	const auto color = CreateColor4<int>(1,2,3);
	std::cout << color << std::endl;

	const auto color2 = CreateColor4<int>(1,2,3,4);
	std::cout << color2 << std::endl;

    return 0;
}

#endif
