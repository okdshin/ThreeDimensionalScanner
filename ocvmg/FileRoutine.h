#pragma once
//FileRoutine:20120707
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "../mg/MiddleGraphics.h"
#include "Routine.h"

namespace ocvmg
{
auto LoadColor4bImageFile(const std::string& file_name) 
->mg::Color4bImage
{
	const auto cvmat = cv::imread(file_name.c_str());
	return ConvertCvMatToColor4bImage(cvmat.clone());
}

auto SaveColor4bImageFile(const std::string& file_name, const mg::Color4bImage& image)
->void
{
	const auto mat_image = ocvmg::ConvertColor4bImageToCvMat(image);
	cv::imwrite(file_name.c_str(), mat_image);
}

auto LoadColor4bMovieFile(const std::string& file_name) 
->mg::Color4bMovie
{
	auto cap = cv::VideoCapture(file_name);
	if(!cap.isOpened())
	{
		std:: cout << "movie open error!" << std::endl;
		return mg::Color4bMovie();
	}

	auto movie = mg::Color4bMovie();
	const auto width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
	const auto height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
	std::cout << width << ", " << height << std::endl;
	cv::Mat cvframe;//(height, width, CV_8UC3);
	unsigned int count = 0;
	while(1)
	{
		cap >> cvframe;
		//std::cout << cvframe.cols << cvframe.rows << std::endl;
		if(cvframe.empty() == true)
		{
			break;	
		}
		//std::cout << cvframe;
		const auto image = ConvertCvMatToColor4bImage(cvframe);
		movie.AddFrame(image);
		//std::cout << image << std::endl;
		std::cout << count++ << std::endl;
	}
	return movie;
	//return mg::Color4bMovie();
}

}

