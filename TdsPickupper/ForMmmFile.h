#pragma once
#include <iostream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include "./common/Tuple.h"
#include "./common/Array2d.h"
#include "./common/List.h"

namespace mmm
{

using byte = unsigned char;
using Pixel = common::Tuple<byte, 4>;
Pixel CreatePixel(byte e0, byte e1, byte e2, byte e3 = 0);
using Image = common::Array2d<Pixel>;
void SaveImage(std::ostream& os, const Image& image);
Image LoadImage(std::istream& is);
class Movie
{
public:
    unsigned int GetWidth()
    {
        return this->GetWidth();
    }
    unsigned int GetHeight()
    {
        return this->GetHeight();
    }
    unsigned int GetSize()
    {
        return this->image_list.GetSize();
    }

    void Add(const Image& image)
    {
        this->image_list.Add(image);
    }
private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & this->image_list;
    }
private:

    common::List<Image> image_list;
};
void SaveMovie(std::ostream& os, const Movie& movie);
Movie LoadMovie(std::istream& is);

}
