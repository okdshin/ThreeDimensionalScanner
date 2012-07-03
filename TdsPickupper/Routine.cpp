#include "Routine.h"
std::string ConvertQStringToStdString(const QString& q_string)
{
	return std::string(q_string.toLocal8Bit());
	//return q_string.toStdString();
}

QImage ConvertIplImageToQImage(IplImage *iplImg)
{
	int h = iplImg->height;
	int w = iplImg->width;
	int channels = iplImg->nChannels;
	QImage qimg = QImage(w, h, QImage::Format_ARGB32);
	char *data = iplImg->imageData;

	for (int y = 0; y < h; y++, data += iplImg->widthStep)
	{
		for (int x = 0; x < w; x++)
		{
            char r = 0;
            char g = 0;
            char b = 0;
            char a = 0;
			if (channels == 1)
			{
				r = data[x * channels];
				g = data[x * channels];
				b = data[x * channels];
			}
			else if (channels == 3 || channels == 4)
			{
				r = data[x * channels + 2];
				g = data[x * channels + 1];
				b = data[x * channels];
			}

			if (channels == 4)
			{
				a = data[x * channels + 3];
				qimg.setPixel(x, y, qRgba(r, g, b, a));
			}
			else
			{
				qimg.setPixel(x, y, qRgb(r, g, b));
			}
		}
	}
	return qimg;

}

/*
void FiltThreshold(const IplImage* const src, IplImage* const dst, const CvScalar& lower, const CvScalar& higher)
{
    int height = src->height;
    int width = src->width;
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            auto pix_color = cvGet2D(src, x, y);
            if(lower.val[0] <= pix_color.val[0] && pix_color.val[0] < higher.val[0]
                    && lower.val[1] <= pix_color.val[1] && pix_color.val[1] < higher.val[1]
                    && lower.val[2] <= pix_color.val[2] && pix_color.val[2] < higher.val[2]
                    && lower.val[3] <= pix_color.val[3] && pix_color.val[3] < higher.val[3])
            {

            }
        }
    }
}
*/
#ifdef UNIT_TEST
#include <iostream>

int main()
{
	std::cout << ConvertQStringToStdString(QString("hello\n"));
	return 0;

}

#endif
