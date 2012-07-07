#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <memory>

namespace ocv
{


class MovieLoader
{
public:
    MovieLoader()
        :file_capture(NULL)
	{
	}

	~MovieLoader()
	{
        if(this->file_capture != NULL)
        {
            cvReleaseCapture(&this->file_capture);
        }
	}

    void Load(const std::string& file_name)
    {
        if(this->file_capture != NULL)
        {
            cvReleaseCapture(&this->file_capture);
        }
        this->file_capture = cvCreateFileCapture(file_name.c_str());
        if(this->file_capture == NULL){
			std::cout << "ERROR!!!!" << std::endl;
		}
        IplImage* cv_image = cvQueryFrame(this->file_capture);//Init the video read
		while(true)
		{
            //std::cout << "=" << std::flush;
            cv_image = cvQueryFrame(this->file_capture);//Init the video read
			if(cv_image == NULL)
			{
				break;	
			}

            auto resized = cvCreateImage(cvSize(320, 240), IPL_DEPTH_8U, 3);
            cvResize(cv_image, resized);
            this->cv_image_array.push_back(resized);

            //this->cv_image_array.push_back(cv_image);

		}
	}

    int GetMovieLength()
    {
        return this->cv_image_array.size()-1;
    }

    IplImage* GetFrame(int frame_number)
	{
        IplImage* image = this->cv_image_array.at(frame_number);
        return image;
    }

    double GetMovieCodec()
    {
        return cvGetCaptureProperty(this->file_capture, CV_CAP_PROP_FOURCC);
    }

    double GetMovieFps()
    {
        return cvGetCaptureProperty(this->file_capture, CV_CAP_PROP_FPS);
    }

    CvSize GetMovieSize()
    {
        auto width = static_cast<int>(cvGetCaptureProperty(this->file_capture, CV_CAP_PROP_FRAME_WIDTH));
        auto height = static_cast<int>(cvGetCaptureProperty(this->file_capture, CV_CAP_PROP_FRAME_HEIGHT));
        return cvSize(width, height);
    }

private:
    CvCapture* file_capture;
    std::vector<IplImage*> cv_image_array;

};

}
