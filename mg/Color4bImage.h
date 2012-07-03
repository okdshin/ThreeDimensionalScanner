#pragma once
//Color4bImage:20120625
#include <iostream>
#include "Byte.h"
#include "Image.h"
#include "Color4b.h"

namespace mg
{
using Color4bImage = Image<Byte, 4>;

auto CreateColor4bImage(
	const common::Size2ui& size, 
	std::function<Color4b (const unsigned int, const unsigned int)> element_generator
) 
-> Color4bImage
{
	return CreateImage<Byte, 4>(size, element_generator);	
}
}

