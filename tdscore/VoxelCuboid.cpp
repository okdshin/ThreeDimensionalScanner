#ifdef UNIT_TEST
#include "VoxelCuboid.h"
#include <iostream>

using namespace tdscore;

int main(int argc, char* argv[])
{
	const auto voxel_cuboid = CreateVoxelCuboid<int>(
		common::Size3ui(5,5,5),
		1,
		[](const unsigned int x, const unsigned int y, const unsigned int z) -> int
		{
			return x+y+z;
		}
	);
	std::cout << voxel_cuboid << std::endl;

    return 0;
}

#endif
