#ifndef PICKUPPER_H
#define PICKUPPER_H
#include<opencv2/opencv.hpp>
#include<vector>
#include "MaskCreator.h"

namespace fmv
{

class Pickupper
{
    Pickupper(){}
public:

    Pickupper(unsigned int mask_number)
        : mask_creator_array(mask_number)
    {
    }

    ~Pickupper()
    {
        cvReleaseImage(&this->pickupped);
    }

    void SetImageSize(const CvSize& image_size)
    {
        /*
        if(this->pickupped != NULL)
        {
            cvReleaseImage(&this->pickupped);
        }
        */
        this->pickupped = cvCreateImage(image_size, IPL_DEPTH_8U, 3);
        for(auto& mc : this->mask_creator_array)
        {
            mc.SetMaskSize(image_size);
        }
    }

    void SetMaskThresholdLower(unsigned int mask_creator_index, unsigned int color_index, char value)
    {
        this->mask_creator_array.at(mask_creator_index).SetThresholdLower(color_index, value);
    }

    void SetMaskThresholdHigher(unsigned int mask_creator_index, unsigned int color_index, char value)
    {
        this->mask_creator_array.at(mask_creator_index).SetThresholdHigher(color_index, value);
    }

    IplImage* Pickup(IplImage* src)
    {
        /*
        auto image_size = cvGetSize(this->pickupped);
        cvReleaseImage(&this->pickupped);
        this->pickupped = cvCreateImage(image_size, IPL_DEPTH_8U, 3);
        */
        cvSet(this->pickupped, cvScalar(0,0,0));

        auto integrated_mask = cvCreateImage(cvGetSize(src), IPL_DEPTH_8U, 1);
        cvSet(integrated_mask, cvScalar(0,0,0));

        for(auto& mc : this->mask_creator_array)
        {
            auto mask = mc.CreateMask(src);
            cvOr(integrated_mask, mask, integrated_mask);

        }

        cvNot(integrated_mask, integrated_mask);
        cvCopy(src, this->pickupped, integrated_mask);

        return this->pickupped;
    }

private:
    IplImage* pickupped;
    std::vector<MaskCreator> mask_creator_array;
};

}
#endif // PICKUPPER_H
