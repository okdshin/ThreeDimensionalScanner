#pragma once
//Color:20120604
#include <iostream>
#include "../common/Vector.h"
namespace mg
{

template<class ElementType, unsigned int DimensionNum>
class Color
{
public:
	Color():color_vector(){}
	Color(const common::Vector<ElementType, DimensionNum>& color_vector)
		:color_vector(color_vector){}

	common::Vector<ElementType, DimensionNum> GetColorVector()const
	{ 
		return this->color_vector; 
	}

	ElementType operator()(unsigned int index)const
	{
		return this->color_vector(index);
	}

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & this->color_vector;
    }

private:
	common::Vector<ElementType, DimensionNum> color_vector;
};

template<class ElementType, unsigned int DimensionNum>
std::ostream& operator<<(std::ostream& os, const Color<ElementType, DimensionNum>& color)
{
	os << "(color:" << color.GetColorVector() << ")";
	return os;
}

template<class ElementType, unsigned int DimensionNum>
bool operator==(const Color<ElementType, DimensionNum>& left, const Color<ElementType, DimensionNum>& right)
{
	return left.GetColorVector() == right.GetColorVector();
}

template<class ElementType, unsigned int DimensionNum>
bool operator!=(const Color<ElementType, DimensionNum>& left, const Color<ElementType, DimensionNum>& right)
{
	return left.GetColorVector() != right.GetColorVector();
}
}

