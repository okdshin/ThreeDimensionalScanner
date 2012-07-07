#ifdef UNIT_TEST
#include "Color4bMovieRoutine.h"
#include <iostream>

using namespace ocvmg;

int main(int argc, char* argv[])
{
	const auto movie = LoadMovieFile("sample.avi");
	//std::cout << movie << std::endl;

    return 0;
}

#endif
