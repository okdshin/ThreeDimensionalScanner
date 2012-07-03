#pragma once
//VoxelList:20120625
#include <iostream>
#include "../common/List.h"
#include "Voxel.h"

namespace tdscore
{
template<class ValueType>
using VoxelList = common::List<Voxel<ValueType>>;
}

