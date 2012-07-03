#ifndef MMMROUTINE_H
#define MMMROUTINE_H
//#include "ForMmmFile.h"
#include <opencv2/opencv.hpp>
#include "../mg/MiddleGraphics.h"
namespace mmm
{
mg::Color4bImage ConvertIplImageToMmmImage(const IplImage* ipl_image);

void ConvertMmmImageToIplImage(const mg::Color4bImage& image, IplImage* ipl_image);

}


#endif // MMMROUTINE_H
