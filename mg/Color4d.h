#pragma once
//Color4d:20120604
#include <iostream>
#include "Color4.h"

namespace mg
{

using Color4d = Color4<double>;

Color4d CreateColor4d(
	const double e0, 
	const double e1, 
	const double e2, 
	const double e3=0.0
)
{
	return CreateColor4<double>(e0, e1, e2, e3);	
}

}

