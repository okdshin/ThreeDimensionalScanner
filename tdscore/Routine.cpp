#ifdef UNIT_TEST
#include "Routine.h"
#include <iostream>

using namespace tdscore;

void TestTraceVoxelLoopOnLayer()
{
	const auto layer = CreateVoxelLayer<int>(
		common::Size2ui(100,100), 
		1.5,
		[](const unsigned int x, const unsigned int y)
		{
			int val = 0;
			if((x-50)*(x-50) + (y-50)*(y-50) <= 900)
			{
				val = 1;	
			}
			else
			{
				val = 0;	
			}

			return val;;
		}
	);
	//std::cout << layer << std::endl;


	const auto trace_list = TraceVoxelLoopOnLayer<int>(
		layer, 
		//common::CreateVector2i(20,50), 
		//common::CreateVector2i(1,0), 
		[](const int& val)
		{
			return val == 1;
		}
	);

	std::cout << trace_list << std::endl;
	
	auto image = mg::CreateColor4bImage(
		layer.GetSize(),
		[](const unsigned int x, const unsigned int y)
		{
			return mg::CreateColor4b(0,0,0);
		}
	);

	for(const auto& voxel : trace_list)
	{
		std::cout << voxel.GetCoord() << std::endl;;
		image(
			static_cast<unsigned int>(voxel.GetCoord()(0)+50), 
			static_cast<unsigned int>(voxel.GetCoord()(1)+50)) 
										= mg::CreateColor4b(255,255,255);
	}

	ocvmg::SaveColor4bImageFile("trace_image.jpg", image);

}

int main(int argc, char* argv[])
{
	TestTraceVoxelLoopOnLayer();

    return 0;
}


#endif
