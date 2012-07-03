#ifndef MASKCREATOR_H
#define MASKCREATOR_H
#include <opencv2/opencv.hpp>

namespace fmv
{

class MaskCreator
{
public:
    MaskCreator();
    ~MaskCreator();

    void SetMaskSize(const CvSize& size);
    void SetThresholdLower(unsigned int color_index, unsigned char value);
    void SetThresholdHigher(unsigned int color_index, unsigned char value);

    IplImage* CreateMask(IplImage* src);
private:
    CvScalar lower, higher;
    IplImage* mask;

};

}
#endif // MASKCREATOR_H
