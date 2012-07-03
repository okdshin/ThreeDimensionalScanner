#pragma once
//Routine:20120623
#include <iostream>
#include "../common/List.h"
#include "../common/Vector3dList.h"
#include "../common/SizeRoutine.h"
#include "ExistenceFlagVoxelList.h"
#include "ExistenceFlagVoxelCuboid.h"

namespace tdscore
{
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
const auto HEX_DIRECTION_LIST = GetHexDirectionList();
const auto OCT_DIRECTION_LIST = GetOctDirectionList();

auto Dig(
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

