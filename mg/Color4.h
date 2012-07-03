#pragma once
//Color:20120529
#include "Color.h"

namespace mg
{

template<class ColorElementType>
using Color4 = Color<ColorElementType, 4>;

template<class ColorElementType>
Color4<ColorElementType> CreateColor4(ColorElementType e0, ColorElementType e1, ColorElementType e2, ColorElementType e3=0)
{
	auto color_vector4 = common::Vector<ColorElementType, 4>();
    color_vector4(0) = e0;
    color_vector4(1) = e1;
    color_vector4(2) = e2;
    color_vector4(3) = e3;
    return Color<ColorElementType, 4>(color_vector4);
}


}

