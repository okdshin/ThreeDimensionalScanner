#pragma once
//ExistenceFlagVoxelCuboid:20120625
#include <iostream>
#include "ExistenceFlag.h"
#include "VoxelCuboid.h"
#include "../utility/CharIndicatorWithTimer.h"
#include "../common/SizeRoutine.h"

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

auto CreateExistenceFlagVoxelCuboid(
	const common::Size3ui& cuboid_size, 
	double voxel_edge_length, 
	const tdscore::ExistenceFlag& initial_value=tdscore::EXIST
)
->tdscore::ExistenceFlagVoxelCuboid
{
	auto indicator = utl::CharIndicatorWithTimer("efvc creation", common::GetVolume(cuboid_size));
	return tdscore::CreateExistenceFlagVoxelCuboid(
		cuboid_size, 
		voxel_edge_length, 
		[&initial_value, &indicator]
		(const unsigned int x, const unsigned int y, const unsigned int z)
		->tdscore::ExistenceFlag
		{
			indicator.CountAndIndicate();
			return initial_value;
		}
	);
	
}

}

