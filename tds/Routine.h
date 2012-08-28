#pragma once
//Routine:20120625
#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>
#include <cmath>
#include "../common/Array3dRoutine.h"
#include "../tdm/ThreeDimensionModel.h"
#include "../mg/MiddleGraphics.h"
#include "../tdscore/TdsCore.h"
#include "../common/Vector.h"
namespace tds
{
auto PrintImage(
	const mg::Color4bImage& image,
	const double theta_radian, 
	const tdscore::ExistenceFlagVoxelCuboid& efvc, 
	const mg::Color4b& back_color,
	const double scale_ratio = 1.0
)
-> tdscore::ExistenceFlagVoxelCuboid
{
	auto converted = common::ConvertElement<tdscore::ExistenceFlagVoxel, tdscore::ExistenceFlagVoxel>(
		efvc,
		[&image, &theta_radian, &back_color, &scale_ratio](const tdscore::ExistenceFlagVoxel& efv)
		{
			const auto vx = efv.GetCoord()(0);
			const auto vy = efv.GetCoord()(1);
			const auto vz = efv.GetCoord()(2);

			const auto image_width = image.GetSize().GetWidth();
			const auto image_height = image.GetSize().GetHeight();
			const int px = (cos(theta_radian)*vy - sin(theta_radian)*vx) +image_width/2.0;
			const int py = vz +image_height/2.0;
			const auto color = image(static_cast<unsigned int>(scale_ratio*px), static_cast<unsigned int>(scale_ratio*py));

			if(efv.GetValue() == tdscore::EXIST)
			{
				if(color == back_color)
				{
					return tdscore::ExistenceFlagVoxel(efv.GetCoord(), tdscore::NOT_EXIST);
				}
			}
			return efv;	

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
			}
			return efb;	
		}
	);
	return converted;

}

auto GetDegreeOfSimilarity(
	const mg::Color4bImage& image1, 
	const mg::Color4bImage& image2
)
->double
{
	assert(image1.GetSize() == image2.GetSize());

	double degree_sum = 0;
	const auto size = image1.GetSize();
	//std::cout << size << std::endl;
	common::ForEachIndex(
		common::Size2ui(size.GetWidth(), size.GetHeight()),
		[&image1, &image2, &degree_sum]
		(
			const unsigned int x, 
			const unsigned int y
		){
			const auto color1 = image1(x, y);
			const auto color2 = image2(x, y);
			const auto vec1 = common::ConvertElementType<mg::Byte, double, 4>(color1.GetColorVector());
			const auto vec2 = common::ConvertElementType<mg::Byte, double, 4>(color2.GetColorVector());

			const auto distance = common::GetSquareLength(vec1-vec2);
			//if(distance != 0)std::cout << "aaaa" << std::endl;
			/*
			if(vec1 != vec2)
			{
				std::cerr << vec1 << vec2 << vec1-vec2 << distance << std::endl;
			}
			*/
			degree_sum = degree_sum + distance; 

		}
	);
	return degree_sum;
}

auto AutoCreateMaskMovie(
	const mg::Color4bMovie& src_movie, 
	unsigned int offset_frame, 
	double range_max_radian, 
	unsigned int dst_frame_num
)
->mg::Color4bMovie
{
	const auto base_frame = src_movie.GetFrame(offset_frame);
	std::vector<std::tuple<double, unsigned int>> index_image_vector;
	for(unsigned int i = offset_frame+1; i < src_movie.GetLength(); i++)
	{
		const auto degree = GetDegreeOfSimilarity(base_frame, src_movie.GetFrame(i));
		index_image_vector.push_back(std::make_tuple(degree, i));
	}
	
	std::sort(
		index_image_vector.begin(), 
		index_image_vector.end(), 
		[](
			const std::tuple<double, unsigned int>& left, 
			const std::tuple<double, unsigned int>& right
		)->bool
		{
			return std::get<0>(left) < std::get<0>(right);	
		}
	);
	
	for(const auto& e : index_image_vector)
	{
		std::cout << std::get<0>(e) << ":" << std::get<1>(e) << std::endl;
	}
	

	return mg::Color4bMovie();
}

auto CreateMaskMovie(
	const mg::Color4bMovie& src_movie, 
	unsigned int offset_frame_min, 
	unsigned int offset_frame_max,
	unsigned int dst_frame_num
)
->mg::Color4bMovie
{
	auto dst_movie = mg::Color4bMovie();
	const auto interval = (offset_frame_max-offset_frame_min)/dst_frame_num;
	for(unsigned int frame_index = 0; frame_index < dst_frame_num; frame_index++)
	{
		const auto frame = src_movie.GetFrame(offset_frame_min + frame_index*interval);
		dst_movie.AddFrame(frame);
	}
	return dst_movie;

}
auto PrintMaskMovie(
	const mg::Color4bMovie& movie, 
	const common::Size3ui& efvc_size, 
	double voxel_edge_length, 
	const mg::Color4b& back_color, 
	double range_max_radian
)
-> tdscore::ExistenceFlagVoxelCuboid
{
	auto printed_efvc = tdscore::CreateExistenceFlagVoxelCuboid(
		efvc_size,
		voxel_edge_length, 
		[](const unsigned int x, const unsigned int y, const unsigned int z)
		{
			return tdscore::EXIST; 
		}
	);
	for(unsigned int i = 0; i < movie.GetLength(); i++)
	{
		const auto image = movie.GetFrame(i);
		const double radian = i*(range_max_radian/movie.GetLength());
		printed_efvc = PrintImage(image, radian, printed_efvc, back_color);
	}	
	return printed_efvc;
}


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
	
	//const auto scaled_group = tdm::Scale(voxel_edge_length, unit_group)
	//const auto group = tdm::Move(voxel_edge_length, scaled_group);
	/*
	const auto group = tdm::Move(
		voxel_edge_length * (voxel.GetCoord()-0.5*common::CreateVector3d(1,1,1)), 
		tdm::Scale(voxel_edge_length, unit_group)
	);
	*/
	const auto group = tdm::Move(
		voxel.GetCoord()-0.5*voxel_edge_length*common::CreateVector3d(1,1,1), 
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

template<class ValueType>
auto GetVoxelLayerSize(const tdscore::VoxelCuboid<ValueType>& voxel_cuboid)
-> common::Size2ui
{
	const auto cuboid_size = voxel_cuboid.GetSize();
	return common::Size2ui(cuboid_size.GetWidth(), cuboid_size.GetHeight());
}

template<class ValueType>
auto GetVoxelLayer(
	const tdscore::VoxelCuboid<ValueType>& voxel_cuboid,
	const double voxel_edge_length,
	const unsigned int layer_index
)
-> tdscore::VoxelLayer<ValueType>
{
	return tdscore::CreateVoxelLayer<ValueType>(
		GetVoxelLayerSize(voxel_cuboid),
		voxel_edge_length,
		[&voxel_cuboid, &layer_index]
		(
			const unsigned int x, 
			const unsigned int y
		)
		{
			return voxel_cuboid(x, y, layer_index).GetValue();
		}
	);
}

/*
template<class ValueType>
auto CountVoxelLayerElement(
	const tdscore::VoxelLayer<ValueType>& voxel_layer,
	std::function<bool (const ValueType& value)> decider
)
-> unsigned int
{
	unsigned int count = 0;
	for(const auto& le : voxel_layer)
	{
		if(decider(le.GetValue()))
		{
			++count;
		}
	}

	return count;
}
*/
//穴の空いていない物体を想定している。穴の空いた物体ではうまくいかないはずだ。
template<class ValueType>
auto ConvertTwoVoxelLayerToSmoothGroup(
	const tdscore::VoxelList<ValueType>& trace_list1,
	const tdscore::VoxelList<ValueType>& trace_list2,
	std::function<tdm::Material (const ValueType& value)> material_generator
)
-> tdm::GroupList
{
	/*
	const auto trace_list1 = TraceVoxelLoopOnLayer<ValueType>(
		voxel_layer1, 
		common::CreateVector2i(20,50), 
		common::CreateVector2i(1,0), 
		[](const int& val)
		{
			return val == 1;
		}
	);
	
	const auto trace_list2 = TraceVoxelLoopOnLayer<ValueType>(
		voxel_layer2, 
		common::CreateVector2i(20,50), 
		common::CreateVector2i(1,0), 
		[](const ValueType& val)
		{
			return val == 1;
		}
	);
	*/
	const auto count1 = trace_list1.GetSize();
	const auto count2 = trace_list2.GetSize();
	
	auto bigger_list = tdscore::VoxelList<ValueType>();
	auto smaller_list = tdscore::VoxelList<ValueType>();
	double count_ratio = 0.0;
	if(count1 > count2)
	{
		bigger_list = trace_list1;
		smaller_list = trace_list2;
		count_ratio = static_cast<double>(count1) / static_cast<double>(count2);
	}
	else
	{
		bigger_list = trace_list2;
		smaller_list = trace_list1;
		count_ratio = static_cast<double>(count2) / static_cast<double>(count1);
	}

	auto group_list = tdm::GroupList();

	auto face_list = tdm::FaceList();
	auto before_bigger_voxel = common::GetBackElement(bigger_list);
	for(const auto& bigger_voxel : bigger_list)
	{
		const auto smaller_voxel = *std::min_element(
			smaller_list.GetElementVector().begin(), 
			smaller_list.GetElementVector().end(),
			[&bigger_voxel](
				const tdscore::Voxel<ValueType>& left, 
				const tdscore::Voxel<ValueType>& right
			){
				return common::GetDistance(left.GetCoord(), bigger_voxel.GetCoord()) 
						< common::GetDistance(right.GetCoord(), bigger_voxel.GetCoord());
			}
		);

		const auto face = tdm::CreateTriFace(
			before_bigger_voxel.GetCoord(), 
			smaller_voxel.GetCoord(), 
			bigger_voxel.GetCoord()
		);

		before_bigger_voxel = bigger_voxel;
		face_list.Add(face);
		const auto group = tdm::Group(
			material_generator(bigger_voxel.GetValue()), 
			face_list
		);
		group_list.Add(group);
	}	

	return group_list;
}


template<class ValueType>
auto ConvertVoxelCuboidToSmoothObject(
	const tdscore::VoxelCuboid<ValueType>& voxel_cuboid,
	std::function<tdm::Material (const ValueType& value)> material_generator
)
-> tdm::Object
{
	return tdm::Object();
}

template<class ValueType>
auto ConvertVoxelLayerToColor4bImage(
	const tdscore::VoxelLayer<ValueType>& layer, 
	std::function<mg::Color4b(const ValueType&)> converter
)
->mg::Color4bImage
{
	const auto image = mg::CreateColor4bImage(
		layer.GetSize(),
		[&layer, &converter](const unsigned int x, const unsigned int y)
		{
			return converter( layer(x,y).GetValue() );
		}
	);
	return image;
	
}

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

