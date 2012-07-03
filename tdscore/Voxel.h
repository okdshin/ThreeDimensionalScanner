#pragma once
//Voxel:20120621
#include <iostream>
#include "../common/Vector.h"

namespace tdscore
{
template<class ValueType>
class Voxel
{
public:
	Voxel():coord(), value(){}
	Voxel(const common::Vector3d& coord, const ValueType& value)
		:coord(coord), value(value){}
	auto GetCoord()const->common::Vector3d{ return this->coord; }
	auto GetValue()const->ValueType{ return this->value; }

private:
	common::Vector3d coord;
	ValueType value;
};

template<class ValueType>
std::ostream& operator<<(std::ostream& os, const Voxel<ValueType>& voxel)
{
	os << boost::format("(coord:%1%, value:%2%)") % voxel.GetCoord() % voxel.GetValue();
	return os;
}


}

