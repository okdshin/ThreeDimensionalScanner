#include "ForMmmFile.h"
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/gzip.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

namespace mmm{

Pixel CreatePixel(byte e0, byte e1, byte e2, byte e3)
{
    auto pixel = Pixel();
    pixel(0) = e0;
    pixel(1) = e1;
    pixel(2) = e2;
    pixel(3) = e3;
    return pixel;
}
/*
std::ostream& operator<<(std::ostream& os, const Pixel& pixel)
{
    os << boost::format("(%1%, %2%, %3%, %4%) ")
        % static_cast<unsigned int>(pixel(0))
        % static_cast<unsigned int>(pixel(1))
        % static_cast<unsigned int>(pixel(2))
        % static_cast<unsigned int>(pixel(3));
    return os;
}
*/


void SaveImage(std::ostream& os, const Image& image)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
    out.push(boost::iostreams::gzip_compressor());
    out.push(os);
    boost::archive::binary_oarchive oa(out);
    oa << image;

}
Image LoadImage(std::istream& is)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(is);
    boost::archive::binary_iarchive ia(in);
    auto image = Image();
    ia >> image;
    return image;
    /*
    boost::archive::text_iarchive ia(is);
    auto image = Image();
    ia >> image;
    return image;
    */
}

void SaveMovie(std::ostream& os, const Movie& movie)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::output> out;
    out.push(boost::iostreams::zlib_compressor());
    out.push(os);
    boost::archive::binary_oarchive oa(out);
    oa << movie;
}
Movie LoadMovie(std::istream& is)
{
    boost::iostreams::filtering_streambuf<boost::iostreams::input> in;
    in.push(boost::iostreams::gzip_decompressor());
    in.push(is);
    boost::archive::binary_iarchive ia(in);
    auto movie = Movie();
    ia >> movie;
    return movie;
    /*
    boost::archive::text_iarchive ia(is);
    auto movie = Movie();
    ia >> movie;
    return movie;
    */
}

}
