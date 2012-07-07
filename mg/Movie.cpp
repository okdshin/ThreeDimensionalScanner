#ifdef UNIT_TEST
#include "Movie.h"
#include "Byte.h"
#include <iostream>

using namespace mg;

int main(int argc, char* argv[])
{

	auto movie = Movie<Byte, 4>();
	std::cout << movie << std::endl;

    return 0;
}

#endif
