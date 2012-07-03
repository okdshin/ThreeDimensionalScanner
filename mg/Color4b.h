#pragma once
//Color4b:20120604
#include <iostream>
#include "Color4.h"
#include "Byte.h"
namespace mg
{

using Color4b = Color4<Byte>;

Color4b CreateColor4b(const Byte e0, const Byte e1, const Byte e2, const Byte e3=0)
{
	return CreateColor4<Byte>(e0, e1, e2, e3);
}

}

