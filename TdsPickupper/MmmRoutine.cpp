#include "MmmRoutine.h"
#include <opencv2/opencv.hpp>


namespace mmm
{
mg::Color4bImage ConvertIplImageToMmmImage(const IplImage* ipl_image){
    auto width = ipl_image->width;
    auto height = ipl_image->height;
    auto mmm_image = mg::CreateColor4bImage(
        common::Size2ui(width, height),
        [&ipl_image](const unsigned int x, const unsigned int y)
        {
            const auto color = cvGet2D(ipl_image, y, x);
            return mg::CreateColor4b(color.val[0], color.val[1], color.val[2], color.val[3]);
        }
    );
    return mmm_image;
}

void ConvertMmmImageToIplImage(const mg::Color4bImage& image, IplImage* ipl_image)
{
    auto width = image.GetSize().GetWidth();
    auto height = image.GetSize().GetHeight();
    for(unsigned int x = 0; x < width; x++)
    {
        for(unsigned int y = 0; y < height; y++)
        {
            const auto pixel = image(x,y);
            cvSet2D(ipl_image, y, x, cvScalar(pixel(0), pixel(1), pixel(2), pixel(3)));
        }
    }
}
}
