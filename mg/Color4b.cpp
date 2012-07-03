#ifdef UNIT_TEST
#include "Color4b.h"
#include <iostream>

using namespace mg;

int main(int argc, char* argv[])
{
	const auto c4b = CreateColor4b(1,2,3);
	std::cout << c4b << std::endl;

    return 0;
}

#endif
