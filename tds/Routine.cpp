#ifdef UNIT_TEST
#include "Routine.h"
#include <iostream>
#include <fstream>

using namespace tds;

void TestImagePrint()
{
	const auto image_width = 10;
	const auto image_height = 10;
	const auto image = mg::CreateColor4bImage(
		common::Size2ui(image_width, image_height),
		[](const unsigned int x, const unsigned int y) -> mg::Color4b
		{
			if(4 < (x-image_width/2)*(x-image_width/2)+(y-image_height/2)*(y-image_height/2) && (x-image_width/2)*(x-image_width/2)+(y-image_height/2)*(y-image_height/2) < (image_width/2)*(image_width/2))
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
				return mg::CreateColor4b(0,0,0,0);	
			}
		}
	);

	std::cout << image << std::endl;


	const double ratio = 1;
	const auto efvc = tdscore::CreateExistenceFlagVoxelCuboid(
		common::Size3ui((image_width-1)*ratio, (image_height-1)*ratio, (image_width-1)*ratio), 
		1/ratio, 
		[](const unsigned int x, const unsigned int y, const unsigned int z)
		{
			return tdscore::EXIST; 
		}
	);

	const auto back_color = mg::CreateColor4b(0,0,0,0);
	const auto printed_efvc = PrintImage(image, efvc, back_color);
	std::cout << printed_efvc << std::endl;
	const auto efvl = tdscore::Dig(printed_efvc, tdscore::HEX_DIRECTION_LIST);
	std::cout << efvl << std::endl;
	OutputVoxelListAsObjFile<tdscore::ExistenceFlag>(
		"test_object", 
		1/ratio,
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

int main(int argc, char* argv[])
{
	TestImagePrint();
    return 0;
}

#endif
