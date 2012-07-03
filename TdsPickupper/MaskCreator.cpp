#include "MaskCreator.h"
#include <cassert>
namespace fmv
{

MaskCreator::MaskCreator()
{
    this->lower = cvScalar(127,127,127);
    this->higher = cvScalar(255,255,255);
}
void MaskCreator::SetMaskSize(const CvSize& size)
{
    this->mask = cvCreateImage(size, IPL_DEPTH_8U, 1);
}

MaskCreator::~MaskCreator()
{
    cvReleaseImage(&this->mask);
}

void MaskCreator::SetThresholdLower(unsigned int color_index, unsigned char value)
{
    assert(color_index < 3);
    std::cout << "low_val" << value << std::endl;
    this->lower.val[color_index] = value;
}

void MaskCreator::SetThresholdHigher(unsigned int color_index, unsigned char value)
{
    assert(color_index < 3);
    std::cout << "high_val" << value << std::endl;
    this->higher.val[color_index] = value;
}

IplImage* MaskCreator::CreateMask(IplImage* src)
{
    cvSet(this->mask, cvScalar(0,0,0));
    cvInRangeS(src, this->lower, this->higher, this->mask);
    return this->mask;
}

}
