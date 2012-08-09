#ifdef UNIT_TEST
#include "VoxelLayer.h"
#include <iostream>

using namespace tdscore;

int main(int argc, char* argv[])
{
	const auto layer = 
		CreateVoxelLayer<int>(
			common::Size2ui(10,10), 
			[](const unsigned int x, const unsigned int y)
			{
				return CreateVoxel<int>(x, y, 0, x+y);
			}
		);

	std::cout << layer << std::endl;
    return 0;
}

#endif
