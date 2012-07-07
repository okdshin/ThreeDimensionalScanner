#ifdef UNIT_TEST
#include "FileRoutine.h"
#include <iostream>

using namespace ocvmg;

int main(int argc, char* argv[])
{
	const auto image = OpenImageFile("sample.jpg");
	std::cout << image << std::endl;

    return 0;
}

#endif
