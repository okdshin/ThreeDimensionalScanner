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
	std::function<Voxel<ValueType> (const unsigned int, const unsigned int)> element_initializer
)
-> VoxelLayer<ValueType>
{
	return common::CreateArray2d<Voxel<ValueType>>(
		size, 
		[&element_initializer](const unsigned int x, const unsigned int y)
		{
			return element_initializer(x, y);
		}
	);
}

}

