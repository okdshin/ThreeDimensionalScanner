/*
 * INFO 
 * To use this please link following libs for compression and serialization
 * 	boost_iostreams
 *  boost_serialization
 */
#pragma once
//Movie:20120529
#include <iostream>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include "../common/List.h"
#include "Image.h"

namespace mg
{

template<class ColorElementType, unsigned int ColorDimensionNum>
class Movie
{
public:
	Movie(){}

    unsigned int GetFrameSize()
    {
        return this->image_list(0).GetSize();
    }
    
	unsigned int GetLength()
    {
        return this->image_list.GetSize();
    }

    void AddFrame(const Image<ColorElementType, ColorDimensionNum>& image)
    {
        this->image_list.Add(image);
    }

	auto begin()const 
	-> typename common::List<Image<ColorElementType, ColorDimensionNum>>::const_iterator
	{
		return this->image_list.begin();		
	};
	
	auto end()const 
	-> typename common::List<Image<ColorElementType, ColorDimensionNum>>::const_iterator
	{
		return this->image_list.end();		
	};

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & this->image_list;
    }
private:

    common::List<Image<ColorElementType, ColorDimensionNum>> image_list;
};


template<class ColorElementType, unsigned int ColorDimensionNum>
void SaveMovie(std::ostream& os, const Movie<ColorElementType, ColorDimensionNum>& movie)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
    out.push(boost::iostreams::zlib_compressor());
    out.push(os);
    boost::archive::binary_oarchive oa(out);
    oa << movie;
}

template<class ColorElementType, unsigned int ColorDimensionNum>
Movie<ColorElementType, ColorDimensionNum> LoadMovie(std::istream& is)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(is);
    boost::archive::binary_iarchive ia(in);
    auto movie = Movie<ColorElementType, ColorDimensionNum>();
    ia >> movie;
    return movie;
}

template<class ColorElementType, unsigned int ColorDimensionNum>
std::ostream& operator <<(
	std::ostream& os, 
	const Movie<ColorElementType, ColorDimensionNum>& movie
)
{
	for(const auto& image : movie)
	{
		os << image << std::endl;	
	}
	
	return os;	
}

}

