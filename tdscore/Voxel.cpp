#ifdef UNIT_TEST
#include "Voxel.h"
#include <iostream>

using namespace tdscore;

int main(int argc, char* argv[])
{
	const auto v = Voxel<int>(common::CreateVector3d(1.1,2.2,3.3), 4);
	std::cout << v << std::endl;

    return 0;
}

#endif
