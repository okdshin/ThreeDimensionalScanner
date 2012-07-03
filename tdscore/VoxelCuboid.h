#pragma once
//VoxelCuboid:20120621
#include <iostream>
#include <functional>
#include "../common/Array3d.h"
#include "../common/Size.h"
#include "Voxel.h"

namespace tdscore
{
template<class ValueType>
using VoxelCuboid = common::Array3d<Voxel<ValueType>>;

template<class ValueType>
auto CreateVoxelCuboid(
	const common::Size3ui& size,
	const double voxel_edge_length,
	std::function<ValueType (
		const unsigned int x, 
		const unsigned int y, 
		const unsigned int z
	)> element_initializer) -> VoxelCuboid<ValueType>
{
	const auto voxel_cuboid = common::CreateArray3d<Voxel<ValueType>>(
		size, 
		[&size, &voxel_edge_length, &element_initializer](const unsigned int x, const unsigned int y, const unsigned int z) -> Voxel<ValueType>
		{
			const auto array_coord = common::CreateVector3d(
				static_cast<double>(x), 
				static_cast<double>(y), 
				static_cast<double>(z)
			);
			const auto size_vect = common::CreateVector3d(
				static_cast<double>(size.GetWidth()), 
				static_cast<double>(size.GetHeight()), 
				static_cast<double>(size.GetDepth())
			);

			const auto coord = voxel_edge_length * (array_coord - 0.5*(size_vect-common::CreateVector3d(1,1,1)));
			const auto value = element_initializer(x, y, z);
			return Voxel<ValueType>(coord, value);
		}
	);
	return voxel_cuboid;
}

}

