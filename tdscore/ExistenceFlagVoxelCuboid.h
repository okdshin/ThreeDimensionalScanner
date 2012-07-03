#pragma once
//ExistenceFlagVoxelCuboid:20120625
#include <iostream>
#include "ExistenceFlag.h"
#include "VoxelCuboid.h"

namespace tdscore
{

using ExistenceFlagVoxelCuboid = VoxelCuboid<ExistenceFlag>;
auto CreateExistenceFlagVoxelCuboid(
	const common::Size3ui& size,
	const double voxel_edge_length,
	std::function<ExistenceFlag (
		const unsigned int x, 
		const unsigned int y, 
		const unsigned int z
	)> element_initializer
) 
-> ExistenceFlagVoxelCuboid
{
	return CreateVoxelCuboid<ExistenceFlag>(size, voxel_edge_length, element_initializer);
}

}

