#ifndef FORMMMROUTINE_H
#define FORMMMROUTINE_H
#include <vector>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/vector.hpp>

namespace mmm
{
using byte = unsigned char;
using uint = unsigned int;

class Pixel
{
public:
    Pixel(uint color_number)
        :color_array(color_number)
    {

    }

    void SetColor(uint index, value)
    {
        this->color_array.at(index) = value;
    };

    byte GetColor(uint index)const
    {
        return this->color_array.at(index);
    };

    friend std::ostream& <<(std::ostream& os, const Pixel& pixel);
private:
    std::vector<byte> color_array;
};

std::ostream& <<(std::ostream& os, const Pixel& pixel)
{
    for(auto color : pixel.color_array)
    {
        os << color << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Pixel& pixel)
{

    for(byte& color : pixel.GetColor())
    {
        is >> color;
    }
    return is;
}

class ImageInfo
{
public:
    ImageInfo(uint width, uint height, uint color_number)
        :width(width)
        ,height(height)
        ,color_number(color_number){}

    uint GetWidth();
    uint GetHeight();
    uint GetColorNumber();

private:
    ImageInfo();

private:
    uint width, height, color_number;
}

std::ostream& operator<<(std::ostream& os, const ImageInfo& inf)
{
    os << info.GetWidth() << " " << info.GetHeight() << " " << info.GetColorNumber() << " ";
}

std::istream& operator>>(std::istream& is, ImageInfo& info)
{
    uint width = 0;
    uint height = 0;
    uint color_number = 0;
    os >> width >> height >> color_number;
    info = ImageInfo(width, height, color_number);
    return os;
}

class Image
{
public:
    Image(uint width, uint height, uint color_number, const ImageData& data)
        :info(width, height, color_number)
        ,data(data){}

    ImageInfo GetInfo()
    {
        return this->info;
    }

    Pixcel GetPixcel(uint x ,uint y)
    {
        return this->pixel_2d_array.at(x).at(y);
    }

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & info & pixcel_2d_array;
    }

private:
    ImageInfo info;
    std::vector<std::vector<Pixel>> pixel_2d_array;
};


class MovieInfo
{
public:
    ImageInfo GetImageInfo()
    {
        return this->image_info;
    }

    void GetFps()
    {
        return this->fps;
    }

    void GetLength()
    {
        return this->length;
    }

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & length & fps & image_info;
    }

private:
    uint length;
    double fps;
    ImageInfo image_info;
}

class Movie
{
public:
    MovieInfo GetInfo()
    {
        return this->info;
    }

    Image GetImage(uint number)
    {
        return this->data_array.at(number);
    }

private:
    friend class boost::serialization::access;

    template<class Archive>
    void serialize( Archive& ar, unsigned int ver )
    {
        ar & info & data_array;
    }

private:
    MovieInfo info;
    std::vector<ImageData> data_array;
}


}
#endif // FORMMMROUTINE_H
