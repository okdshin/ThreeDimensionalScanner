#pragma once
//Routine:20120623
#include <iostream>
#include "../common/List.h"
#include "../common/Array2dRoutine.h"
#include "../common/Vector.h"
#include "../common/Vector3dList.h"
#include "../common/SizeRoutine.h"
#include "VoxelLayer.h"
#include "VoxelList.h"
#include "ExistenceFlagVoxelList.h"
#include "ExistenceFlagVoxelCuboid.h"
#include "../mg/MiddleGraphics.h"
#include "../ocvmg/OpenCvForMiddleGraphics.h"

namespace tdscore
{

template<class ValueType>
auto TraceVoxelLoopOnLayer(
	const VoxelLayer<ValueType>& layer, 
	const common::Vector2i& start_point,
	const common::Vector2i& initial_dir,
	std::function<bool (const ValueType&)> decider
)
->VoxelList<ValueType>
{
	auto dst_list = VoxelList<ValueType>();
	auto dir = initial_dir;
	auto current_point = start_point;
	
	auto search_dir_list = common::List<common::Vector2i>();
	search_dir_list.Add(common::CreateVector2i(-1,1));
	search_dir_list.Add(common::CreateVector2i(0,1));
	search_dir_list.Add(common::CreateVector2i(1,1));
	search_dir_list.Add(common::CreateVector2i(-1,0));
	search_dir_list.Add(common::CreateVector2i(0,0));
	search_dir_list.Add(common::CreateVector2i(1,0));
	search_dir_list.Add(common::CreateVector2i(-1,-1));
	search_dir_list.Add(common::CreateVector2i(0,-1));
	search_dir_list.Add(common::CreateVector2i(1,-1));
	auto index_list = std::vector<std::vector<int>>({
		{2,1,0,3,6,7,8,5},
		{8,5,2,1,0,3,6,7},
		{6,7,8,5,2,1,0,3},
		{0,3,6,7,8,5,2,1}
	});
	
	while(1)
	{
		unsigned int order_index = 0;
		if(dir == search_dir_list(0) || dir == search_dir_list(1))
		{
			order_index = 0;
		}
		else if(dir == search_dir_list(2) || dir == search_dir_list(5))
		{
			order_index = 1;	
		}
		else if(dir == search_dir_list(8) || dir == search_dir_list(7))
		{
			order_index = 2;	
		}
		else if(dir == search_dir_list(6) || dir == search_dir_list(3))
		{
			order_index = 3;	
		}

		for(const auto& index : index_list[order_index])
		{
			const auto search_dir = search_dir_list(index);
			const auto element_voxel = common::GetElement(layer, current_point+search_dir);
			if(decider(element_voxel.GetValue()))
			{
				dst_list.Add(element_voxel);
				dir = search_dir;
				current_point = current_point + search_dir;
				break;
			}

		}

		if(current_point == start_point)
		{
			break;	
		}

		
	}

	return dst_list;
}

template<class ValueType>
auto TraceVoxelLoopOnLayer(
	const VoxelLayer<ValueType>& layer, 
	std::function<bool (const ValueType&)> decider
)
->VoxelList<ValueType>
{
	auto first_find_point = common::Vector2i();
	for(unsigned int x = 0; x < layer.GetSize().GetWidth(); x++)
	{
		for(unsigned int y = 0; y < layer.GetSize().GetHeight(); y++)
		{	
			if(decider( layer(x,y).GetValue() ))
			{
				const auto start_point = common::CreateVector2i(x, y);
				const auto initial_dir = common::CreateVector2i(1, 0);
				return TraceVoxelLoopOnLayer(
					layer, 
					start_point,
					initial_dir,
					decider
				);
			}
		}
		
	}	
	assert(!"no loop found");
}


auto GetOctDirectionList() -> common::List<common::Vector3i>
{
	auto dir_list = common::List<common::Vector3i>();
	for(int x = -1; x < 2; x++)
	{
		for(int y = -1; y < 2; y++)
		{
			for(int z = -1; z < 2; z++)
			{
				if(!(x == 0 && y == 0 && z == 0))
				{	
					const auto dir = common::CreateVector3i(x, y, z);
					dir_list.Add(dir);
				}
			}
			
		}
	}
	return dir_list;
	
}

auto GetHexDirectionList() -> common::List<common::Vector3i>
{
	auto dir_list = common::List<common::Vector3i>();
	dir_list.Add(common::CreateVector3i(1, 0, 0));
	dir_list.Add(common::CreateVector3i(-1, 0, 0));
	dir_list.Add(common::CreateVector3i(0, 1, 0));
	dir_list.Add(common::CreateVector3i(0, -1, 0));
	dir_list.Add(common::CreateVector3i(0, 0, 1));
	dir_list.Add(common::CreateVector3i(0, 0, -1));
	return dir_list;
	
}

auto GetTetDirectionList() -> common::List<common::Vector3i>
{
	auto dir_list = common::List<common::Vector3i>();
	dir_list.Add(common::CreateVector3i(1, 0, 0));
	dir_list.Add(common::CreateVector3i(-1, 0, 0));
	dir_list.Add(common::CreateVector3i(0, 1, 0));
	dir_list.Add(common::CreateVector3i(0, -1, 0));
	//dir_list.Add(common::CreateVector3i(0, 0, 1));
	//dir_list.Add(common::CreateVector3i(0, 0, -1));
	return dir_list;
	
}

const auto TET_DIRECTION_LIST = GetTetDirectionList();
const auto HEX_DIRECTION_LIST = GetHexDirectionList();
const auto OCT_DIRECTION_LIST = GetOctDirectionList();

auto Dig(
	const ExistenceFlagVoxelCuboid& src_efvc,
	const double src_edge_length,
	const common::List<common::Vector3i>& direction_list = HEX_DIRECTION_LIST
) 
-> ExistenceFlagVoxelCuboid
{
	auto dst_efvc = tdscore::CreateExistenceFlagVoxelCuboid(src_efvc.GetSize(), src_edge_length, tdscore::NOT_EXIST);
	common::ForEachIndex(
		src_efvc.GetSize(), 
		[&src_efvc, &direction_list, &dst_efvc](
			const unsigned int x, 
			const unsigned int y, 
			const unsigned int z
		)
		{
			if(src_efvc(x, y, z).GetValue() == EXIST)
			{
				for(const auto dir : direction_list)
				{
					const auto size = src_efvc.GetSize();
					if(
						x+dir(0) <  size.GetWidth() && 
						y+dir(1) <  size.GetHeight() && 
						z+dir(2) <  size.GetDepth()
					){
						if(src_efvc(x+dir(0), y+dir(1), z+dir(2)).GetValue() == NOT_EXIST)
						{
							dst_efvc(x, y, z) = src_efvc(x, y, z);
							return;
						}
					}
				}

				return; 
			}
			else
			{
				return;	
			}
		}
	);
	return dst_efvc;
}

auto DigToList(
	const ExistenceFlagVoxelCuboid& efvc,
	const common::List<common::Vector3i>& direction_list = HEX_DIRECTION_LIST
) 
-> ExistenceFlagVoxelList
{
	auto efvl = tdscore::ExistenceFlagVoxelList();
	common::ForEachIndex(
		efvc.GetSize(), 
		[&efvc, &direction_list, &efvl](
			const unsigned int x, 
			const unsigned int y, 
			const unsigned int z
		)
		{
			if(efvc(x, y, z).GetValue() == EXIST)
			{
				for(const auto dir : direction_list)
				{
					const auto size = efvc.GetSize();
					if(
						x+dir(0) <  size.GetWidth() && 
						y+dir(1) <  size.GetHeight() && 
						z+dir(2) <  size.GetDepth()
					){
						if(efvc(x+dir(0), y+dir(1), z+dir(2)).GetValue() == NOT_EXIST)
						{
							efvl.Add(efvc(x, y, z));
							return;
						}
					}
				}

				return; 
			}
			else
			{
				return;	
			}
		}
	);
	return efvl;
}


}

