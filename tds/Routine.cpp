#ifdef UNIT_TEST
#include "Routine.h"
#include <iostream>
#include <fstream>
#include "../utility/CharIndicatorWithTimer.h"
#include "../ocvmg/OpenCvForMiddleGraphics.h"

using namespace tds;

auto CreateCircleImage(const common::Size2ui& image_size, const double radius, const mg::Color4b& back_color)
->mg::Color4bImage
{
	const auto image_width = image_size.GetWidth();
	const auto image_height = image_size.GetHeight();
	auto indicator = utl::CharIndicatorWithTimer("circle image creation", common::GetArea(image_size));
	return  mg::CreateColor4bImage(
		image_size,
		[&image_width, &image_height, &radius, &back_color, &indicator]
		(const unsigned int x, const unsigned int y) 
		-> mg::Color4b
		{
			indicator.CountAndIndicate();
			if((x-image_width/2)*(x-image_width/2)+(y-image_height/2)*(y-image_height/2) < radius*radius)
			{
				const auto color = mg::CreateColor4b(
					static_cast<mg::Byte>(255*x/image_width), 
					static_cast<mg::Byte>(255*y/image_height), 
					static_cast<mg::Byte>((x+y)/2), 
					0
				);
				return color;
			}
			else
			{
				return back_color;
			}
		}
	);
}


void TestPrintImage()
{
	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto image = CreateCircleImage(common::Size2ui(320,240), 7, back_color);
	ocvmg::SaveColor4bImageFile("image.jpg", image);	

	const auto cuboid_size = common::Size3ui(50,50,50);
	const auto voxel_edge_length = 1.0;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	
	auto printed_efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	
	std::ofstream ofs("pi_timer");
	auto pi_timer = utl::Timer();
	
	for(unsigned int i = 0; i < 180; i+=20)
	{
		const double radian = i*2*M_PI/360;
		//printed_efvc = ParallelPrintImage(image, radian, printed_efvc, back_color, 8);
		printed_efvc = PrintImage(image, radian, printed_efvc, back_color);
	}

	pi_timer("print image:", ofs);

	const auto efvl = tdscore::DigToList(printed_efvc, tdscore::HEX_DIRECTION_LIST);
	
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		"test_object", 
		voxel_edge_length,
		efvl,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::BlueMaterial();
		}
	);

}

void TestPrintMaskMovie()
{
	
	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto circle_image = CreateCircleImage(common::Size2ui(320,240), 7, back_color);
	ocvmg::SaveColor4bImageFile("image.jpg", circle_image);	

	const auto cuboid_size = common::Size3ui(50,50,50);
	const auto voxel_edge_length = 1.0;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	
	std::ofstream ofs("pi_timer");
	auto pi_timer = utl::Timer();

	auto movie = mg::Color4bMovie();
	for(unsigned int i = 0; i < 9; i++)
	{
		movie.AddFrame(circle_image);
	}
	const auto printed_efvc = PrintMaskMovie(movie, efvc.GetSize(), voxel_edge_length, back_color, M_PI);

	pi_timer("print image:", ofs);

	const auto efvl = tdscore::DigToList(printed_efvc, tdscore::TET_DIRECTION_LIST);
	
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		"test_object", 
		voxel_edge_length,
		efvl,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::BlueMaterial();
		}
	);
}

void TestOutputVoxelListObjFile()
{
	const auto efv = tdscore::ExistenceFlagVoxel(common::CreateVector3d(1,2,3), tdscore::EXIST);
	
	auto efvl = tdscore::ExistenceFlagVoxelList();
	efvl.Add(efv);
	
	
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		"test_object", 
		2,
		efvl,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::BlueMaterial();
		}
	);
	
}

auto CreateSphereEfvc(const unsigned int cuboid_edge_size_length, const double voxel_edge_length)
-> tdscore::ExistenceFlagVoxelCuboid
{
	
	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto image = CreateCircleImage(common::Size2ui(320,240), 7, back_color);
	//ocvmg::SaveColor4bImageFile("image.jpg", image);	

	const auto cuboid_size = common::Size3ui(cuboid_edge_size_length, cuboid_edge_size_length, cuboid_edge_size_length);
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	
	auto printed_efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	//std::ofstream ofs("pi_timer");
	//auto pi_timer = utl::Timer();
	
	for(unsigned int i = 0; i < 180; i+=20)
	{
		const double radian = i*2*M_PI/360;
		//printed_efvc = ParallelPrintImage(image, radian, printed_efvc, back_color, 8);
		printed_efvc = PrintImage(image, radian, printed_efvc, back_color);
	}

	return printed_efvc;
}

auto CreateSphereDiggedEfvc(
	const unsigned int cuboid_edge_size_length, 
	const double voxel_edge_length, 
	const common::List<common::Vector3i>& direction_list = tdscore::HEX_DIRECTION_LIST
)
-> tdscore::ExistenceFlagVoxelCuboid
{
	const auto sphere = CreateSphereEfvc(cuboid_edge_size_length, voxel_edge_length);
	return tdscore::Dig(sphere, voxel_edge_length, direction_list);
}

void TestGetDegreeOfSimilarity()
{
	const auto image_width = 20;
	const auto image_height = 20;
	const auto image1 = mg::CreateColor4bImage(
		common::Size2ui(image_width, image_height),
		[](const unsigned int x, const unsigned int y) -> mg::Color4b
		{
			if((x-image_width/2)*(x-image_width/2)+(y-image_height/2)*(y-image_height/2) < (image_width/4)*(image_width/4))
			{
				const auto color = mg::CreateColor4b(
					static_cast<mg::Byte>((static_cast<double>(x)/image_width)*255), 
					static_cast<mg::Byte>((static_cast<double>(y)/image_height)*255), 
					static_cast<mg::Byte>((x+y)/2), 
					0
				);
				return color;
			}
			else
			{
				return mg::CreateColor4b(1,255,1,0);	
			}
		}
	);

	const auto image2 = mg::CreateColor4bImage(
		common::Size2ui(image_width, image_height),
		[](const unsigned int x, const unsigned int y) -> mg::Color4b
		{
			if((x-image_width/2)*(x-image_width/2)+(y-image_height/2)*(y-image_height/2) < (image_width/3)*(image_width/3))
			{
				const auto color = mg::CreateColor4b(
					static_cast<mg::Byte>((static_cast<double>(x)/image_width)*255), 
					static_cast<mg::Byte>((static_cast<double>(y)/image_height)*25), 
					static_cast<mg::Byte>((x+y)/4), 
					0
				);
				return color;
			}
			else
			{
				return mg::CreateColor4b(255,1,1,0);	
			}
		}
	);
	const double degree = GetDegreeOfSimilarity(image1, image2);
	
	std::cout << "degree:" << degree << std::endl;
}

void TestCreateMaskMovie()
{
	const auto src_movie = ocvmg::LoadColor4bMovieFile("mini_converted_sample.avi");
	
	const auto movie = CreateMaskMovie(src_movie, 20, 65, 9);
	for(unsigned int i = 0; i < movie.GetLength(); i++)
	{
		std::cout << movie.GetLength() << std::endl;
	}
}

void TestGetVoxelLayerSize()
{
	const auto cuboid_size = common::Size3ui(40,40,40);
	const auto voxel_edge_length = 2.5;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	const auto layer_size = GetVoxelLayerSize<tdscore::ExistenceFlag>(efvc);	
	std::cout << layer_size << std::endl;
}


void TestGetVoxelLayer()
{
	const auto cuboid_size = common::Size3ui(5,5,5);
	const auto voxel_edge_length = 1.0;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);
	for(unsigned int i = 0; i < 5; i++)
	{
		const auto layer = GetVoxelLayer<tdscore::ExistenceFlag>(efvc, voxel_edge_length, i);
		std::cout << layer << std::endl;
	}
	
}
/*
void TestCountVoxelLayerElement()
{
	auto sphere_efvc = CreateSphereDiggedEfvc(50, 1.0);
	
	const auto count = CountVoxelLayerElement<tdscore::ExistenceFlag>(
		GetVoxelLayer(sphere_efvc, 20),
		tdscore::IsExistenceFlagExist
	);	
	std::cout << count << std::endl;
}
*/
void TestCreateVoxelSetObjFile()
{
	const auto cuboid_size = common::Size3ui(40,40,40);
	const auto voxel_edge_length = 2.5;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);

	const auto src_movie = ocvmg::LoadColor4bMovieFile("mini_converted_sample.avi");
	const auto movie = CreateMaskMovie(src_movie, 18, 42, 9);
	
	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto printed_efvc = PrintMaskMovie(movie, efvc.GetSize(), voxel_edge_length, back_color, M_PI);

	const auto efvl = tdscore::DigToList(printed_efvc, tdscore::TET_DIRECTION_LIST);
	std::cout << efvl << std::endl;
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		"test_object", 
		voxel_edge_length,
		efvl,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::BlueMaterial();
		}
	);
	
}

void TestCreateVoxelSetObjFile(
	const std::string& movie_file_name, 
	const unsigned int start_frame, 
	const unsigned int end_frame
)
{
	const auto cuboid_size = common::Size3ui(40,40,40);
	const auto voxel_edge_length = 2.5;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(cuboid_size, voxel_edge_length);

	const auto src_movie = ocvmg::LoadColor4bMovieFile(movie_file_name.c_str());
	const auto movie = CreateMaskMovie(src_movie, 18, 42, 9);
	
	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto printed_efvc = PrintMaskMovie(movie, efvc.GetSize(), voxel_edge_length, back_color, M_PI);

	const auto efvl = tdscore::DigToList(printed_efvc, tdscore::HEX_DIRECTION_LIST);
	std::cout << efvl << std::endl;
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		movie_file_name.c_str(), 
		voxel_edge_length,
		efvl,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::DonutsMaterial();
		}
	);
	
}

/*
void TestCreateSmoothObjFile()
{
	const double voxel_edge_length = 1.0;
	auto sphere_efvc = CreateSphereDiggedEfvc(50, voxel_edge_length);
	
	const auto layer1 = GetVoxelLayer(sphere_efvc, voxel_edge_length, 25);
	const auto layer2 = GetVoxelLayer(sphere_efvc, voxel_edge_length, 25);

	const auto trace_list1 = tdscore::TraceVoxelLoopOnLayer<tdscore::ExistenceFlag>(
		layer1, 
		[](const tdscore::ExistenceFlag& val)
		{
			return val == 1;
		}
	);
	
	const auto trace_list2 = tdscore::TraceVoxelLoopOnLayer<tdscore::ExistenceFlag>(
		layer2, 
		[](const tdscore::ExistenceFlag& val)
		{
			return val == 1;
		}
	);

	const auto group_list = ConvertTwoVoxelLayerToSmoothGroup<tdscore::ExistenceFlag>(
		trace_list1,
		trace_list2,
		[](const tdscore::ExistenceFlag& ef)
		{
			return tdm::BlueMaterial();
		}
	);
	const auto object = tdm::Object(group_list);
	OutputObjectAsObjFile("smooth_test_object", object);
	
}
*/
int main(int argc, char* argv[])
{
	//TestPrintImage();
	//TestPrintMaskMovie();
    //TestGetDegreeOfSimilarity();
	//TestCreateMaskMovie();
	std::string movie_file_name = "mini_converted_sample.avi";
	std::cout << "prease put target movie file name: " << std::flush;
	std::cin >> movie_file_name;

	unsigned int start_frame = 18;
	std::cout << "prease put start frame number: " << std::flush;
	std::cin >> start_frame;
	
	unsigned int end_frame = 42;
	std::cout << "prease put end frame number: " << std::flush;
	std::cin >> end_frame;

	TestCreateVoxelSetObjFile
	(
		movie_file_name,
		start_frame,
		end_frame
	);
	//TestGetVoxelLayer();
	//TestCountVoxelLayerElement();
	//TestCreateSmoothObjFile();
	
	return 0;
}

#endif
