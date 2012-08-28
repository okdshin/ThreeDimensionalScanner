#pragma once
//VoxelLayer:20120805
#include <iostream>
#include "../common/Array2d.h"
#include "Voxel.h"

namespace tdscore
{
template<class ValueType>
using VoxelLayer = common::Array2d<Voxel<ValueType>>;

template<class ValueType>
auto CreateVoxelLayer(
	const common::Size2ui& size, 
	const double voxel_edge_length,
	std::function<ValueType (const unsigned int, const unsigned int)> element_initializer
)
-> VoxelLayer<ValueType>
{
	return common::CreateArray2d<Voxel<ValueType>>(
		size, 
		[&size, &voxel_edge_length, &element_initializer](const unsigned int x, const unsigned int y)
		{
			const auto array_coord = common::CreateVector2d(
				static_cast<double>(x), 
				static_cast<double>(y) 
			);
			const auto size_vect = common::CreateVector2d(
				static_cast<double>(size.GetWidth()), 
				static_cast<double>(size.GetHeight()) 
			);

			const auto coord2d = voxel_edge_length * (array_coord - 0.5*(size_vect-common::CreateVector2d(1,1)));
			const auto coord3d = common::CreateVector3d(coord2d(0), coord2d(1), 0);
			const auto value = element_initializer(x, y);
			
			return Voxel<ValueType>(coord3d, value);

		}
	);
}

}

