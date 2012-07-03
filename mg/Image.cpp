#ifdef UNIT_TEST
#include <iostream>
#include <fstream>
#include "Image.h"
#include "Color4b.h"
#include "Byte.h"

using namespace mg;

int main(int argc, char* argv[])
{
	
	const auto image = CreateImage<Byte, 4>(
		common::Size2ui(4,3),
		[](const unsigned int x, const unsigned int y) -> Color4b
		{
			const auto color = CreateColor4b(
				static_cast<Byte>(x), 
				static_cast<Byte>(y), 
				static_cast<Byte>((x+y)/2), 
				0
			);
			return color;
		}
	);

	std::cout << image << std::endl;

	std::ofstream ofs("image.img");
	SaveImage<Byte, 4>(ofs, image);
	std::ifstream ifs("image.img");
	auto image2 = LoadImage<Byte,4>(ifs);
	std::cout << image2 << std::endl;

    return 0;
}

#endif
