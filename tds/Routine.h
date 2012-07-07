#pragma once
//Routine:20120625
#include <iostream>
#include <cmath>
#include "../common/Array3dRoutine.h"
#include "../tdm/ThreeDimensionModel.h"
#include "../mg/MiddleGraphics.h"
#include "../tdscore/TdsCore.h"
namespace tds
{
auto PrintImage(
	const mg::Color4bImage& image,
	const double theta_radian, 
	const tdscore::ExistenceFlagVoxelCuboid& efvc, 
	const mg::Color4b& back_color/*, rotate_radian*/
)
-> tdscore::ExistenceFlagVoxelCuboid
{
	auto converted = common::ConvertElement<tdscore::ExistenceFlagVoxel, tdscore::ExistenceFlagVoxel>(
		efvc,
		[&image, &theta_radian, &back_color](const tdscore::ExistenceFlagVoxel& efb){
			const auto coord = efb.GetCoord();
			const auto image_size = image.GetSize();
			/*
			const auto index_coord = common::CreateVector3i(
				static_cast<int>(coord(0)),
				static_cast<int>(coord(1)),
				static_cast<int>(coord(2))
			);
			*/
			//std::cout << static_cast<int>(0.9*(cos(theta_radian)*coord(1)-sin(theta_radian)*coord(0))+image_size.GetWidth()/2) << std::endl;
			const auto color = image(
				static_cast<int>(0.5*(cos(theta_radian)*coord(1)-sin(theta_radian)*coord(0))+image_size.GetWidth()/2), 
				static_cast<int>(0.5*coord(2)+image_size.GetHeight()/2)
			);

			if(efb.GetValue() == tdscore::EXIST)
			{
				if(color == back_color)
				{
					return tdscore::ExistenceFlagVoxel(efb.GetCoord(), tdscore::NOT_EXIST);
				}
				else
				{
					return efb;
				}
			}
			else
			{
				return efb;	
			}

		}
	);
	return converted;

}

auto ParallelPrintImage(
	const mg::Color4bImage& image,
	const double theta_radian, 
	const tdscore::ExistenceFlagVoxelCuboid& efvc, 
	const mg::Color4b& back_color,
	unsigned int thread_num
)
-> tdscore::ExistenceFlagVoxelCuboid
{
	auto converted = common::ParallelConvertElement<tdscore::ExistenceFlagVoxel, tdscore::ExistenceFlagVoxel>(
		efvc,
		thread_num,
		[&image, &theta_radian, &back_color](const tdscore::ExistenceFlagVoxel& efb){
			const auto coord = efb.GetCoord();
			const auto image_size = image.GetSize();
			const auto color = image(
				static_cast<int>(0.5*(cos(theta_radian)*coord(1)-sin(theta_radian)*coord(0))+image_size.GetWidth()/2), 
				static_cast<int>(0.5*coord(2)+image_size.GetHeight()/2)
			);

			if(efb.GetValue() == tdscore::EXIST)
			{
				if(color == back_color)
				{
					return tdscore::ExistenceFlagVoxel(efb.GetCoord(), tdscore::NOT_EXIST);
				}
				else
				{
					return efb;
				}
			}
			else
			{
				return efb;	
			}

		}
	);
	return converted;

}

/*
auto PrintMovie(const mg::COlor4bMovie& movie)
-> tdscore::ExistenceFlagVoxelCuboid
{
	
}
*/

template<class ValueType>
auto ConvertVoxelToCubeGroup(
	const tdscore::Voxel<ValueType>& voxel, 
	const double voxel_edge_length, 
	std::function<tdm::Material (const ValueType& value)> material_generator
)
-> tdm::Group
{
	const auto cube_face_list = tdm::CreateUnitCubeFaceList();
	const auto material = material_generator(voxel.GetValue());
	const auto unit_group = tdm::Group(material, cube_face_list);
	const auto group = tdm::Move(
		voxel_edge_length * (voxel.GetCoord()-0.5*common::CreateVector3d(1,1,1)), 
		tdm::Scale(voxel_edge_length, unit_group)
	);
	
	return group;
}

template<class ValueType>
auto ConvertVoxelListToCubeSetObject(
	const tdscore::VoxelList<ValueType>& voxel_list, 
	const double voxel_edge_length,
	std::function<tdm::Material (const ValueType& value)> material_generator
) 
-> tdm::Object
{
	const auto group_list = common::ConvertElement<tdscore::Voxel<ValueType>, tdm::Group>(
		voxel_list, 
		[&voxel_edge_length, &material_generator](const tdscore::Voxel<ValueType>& voxel) -> tdm::Group
		{
			return ConvertVoxelToCubeGroup(voxel, voxel_edge_length, material_generator);
		}
	);

	return tdm::Object(group_list);

}
/*
*/
/*
auto ConvertExistenceFlagVoxelToCubeGroup(
	const tdscore::ExistenceFlagVoxel efv,
	const double voxel_edge_length,
	const tdm::Material& material = tdm::GrayMaterial()
)
-> tdm::Group
{
	return ConvertVoxelToCubeGroup<tdscore::ExistenceFlag>(
		efv, 
		voxel_edge_length,
		[&material](const tdscore::ExistenceFlag& ef)
		{
			return material;
		}
	);
}

auto ConvertExistenceFlagVoxelListToCubeSetObject(
	const tdscore::ExistenceFlagVoxelList& efvl,
	const double voxel_edge_length,
	const tdm::Material& material = tdm::GrayMaterial()
)
-> tdm::Object
{
	return ConvertVoxelListToCubeSetObject<tdscore::ExistenceFlag>(
		efvl, 
		voxel_edge_length,
		[&material](const tdscore::ExistenceFlag& ef)
		{
			return material;
		}
	);
}
*/

template<class ValueType>
auto OutputVoxelListAsObjFileFormat(
	std::ostream& obj_file, 
	std::ostream& mtl_file, 
	const std::string& mtl_file_name, 
	const std::string& object_name, 
	const double voxel_edge_length, 
	const tdscore::VoxelList<ValueType>& voxel_list, 
	std::function<tdm::Material (const ValueType&)> material_generator
)
-> void
{
	const auto object = ConvertVoxelListToCubeSetObject<tdscore::ExistenceFlag>(
		voxel_list, 
		voxel_edge_length,
		material_generator
	);

	OutputObjectAsObjFileFormat(
		obj_file, 
		mtl_file, 
		mtl_file_name, 
		object_name, 
		object
	);

	return;
	
}

template<class ValueType>
auto OutputVoxelListAsObjFile(
	const std::string& object_name,
	const double voxel_edge_length,
	const tdscore::VoxelList<ValueType>& voxel_list,
	std::function<tdm::Material (const ValueType&)> material_generator
)
-> void
{
	const auto object = ConvertVoxelListToCubeSetObject<tdscore::ExistenceFlag>(
		voxel_list, 
		voxel_edge_length,
		material_generator
	);

	OutputObjectAsObjFile(object_name, object);
	return;
}

}

