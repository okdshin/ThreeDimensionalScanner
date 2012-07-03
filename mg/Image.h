/*
 * INFO 
 * To use this please link following libs for compression and serialization
 *  boost_iostreams 
 *  boost_serialization
 */

#pragma once
//Image:20120529
#include <iostream>
#include <functional>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "../common/Array2d.h"
#include "../common/SizeRoutine.h"
#include "Color.h"

namespace mg
{

template<class ColorElementType, unsigned int ColorDimensionNum>
class Image
{
public:
	Image(){}

	explicit Image(const common::Array2d<Color<ColorElementType, ColorDimensionNum>>& image_array2d)
		:image_array2d(image_array2d){}

	common::Array2d<Color<ColorElementType, ColorDimensionNum>> GetImageArray2d()const
	{
		return this->image_array2d;	
	}

	Color<ColorElementType, ColorDimensionNum> operator()(unsigned int x, unsigned int y)const
	{
		return this->image_array2d(x, y);
	}

	common::Size2ui GetSize()const{ return this->image_array2d.GetSize(); }
private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & this->image_array2d;
    }
	
private:
	common::Array2d<Color<ColorElementType, ColorDimensionNum>> image_array2d;
};

template<class ColorElementType, unsigned int ColorDimensionNum>
Image<ColorElementType, ColorDimensionNum> CreateImage(
	const common::Size2ui& size, 
	std::function<Color<ColorElementType, ColorDimensionNum> (const unsigned int, const unsigned int)> element_generator
){
	const auto image_array2d = common::CreateArray2d<Color<ColorElementType, ColorDimensionNum>>(size, element_generator);
	return Image<ColorElementType, ColorDimensionNum>(image_array2d);
}

template<class ColorElementType, unsigned int ColorDimensionNum>
std::ostream& operator<<(
	std::ostream& os, 
	const Image<ColorElementType, ColorDimensionNum>& image
){
	common::OutputLikeMatrix(os, image.GetImageArray2d().GetSize(), image.GetImageArray2d());
	return os;
	/*
	const auto size = image.GetImageArray2d().GetSize();
	for(unsigned int y = 0; y < size.GetHeight(); y++)
	{
		for(unsigned int x = 0; x < size.GetWidth(); x++)
		{
			os << image.GetImageArray2d()(x, y) << " ";
		}
		os << "\n";
	}
	return os;
	*/

}


template<class ColorElementType, unsigned int ColorDimensionNum>
void SaveImage(std::ostream& os, const Image<ColorElementType, ColorDimensionNum>& image)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
    out.push(boost::iostreams::gzip_compressor());
    out.push(os);
    boost::archive::binary_oarchive oa(out);
    oa << image;

}

template<class ColorElementType, unsigned int ColorDimensionNum>
Image<ColorElementType, ColorDimensionNum> LoadImage(std::istream& is)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(is);
    boost::archive::binary_iarchive ia(in);
    auto image = Image<ColorElementType, ColorDimensionNum>();
    ia >> image;
    return image;
}

}

