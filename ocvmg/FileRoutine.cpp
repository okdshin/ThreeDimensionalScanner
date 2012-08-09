#ifdef UNIT_TEST
#include "FileRoutine.h"
#include <iostream>

using namespace ocvmg;

int main(int argc, char* argv[])
{
	//const auto image = OpenImageFile("sample.jpg");
	//std::cout << image.GetSize() << std::endl;
	//std::cout << image << std::endl;
	const auto movie = OpenMovieFile("mini_sample.avi");
	//std::cout << movie.GetFrame(0) << std::endl;

    return 0;
}

#endif
