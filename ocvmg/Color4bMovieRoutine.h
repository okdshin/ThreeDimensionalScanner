#pragma once
//Color4bMovieRoutine:20120703
#include <iostream>
#include <string>
#include "../mg/MiddleGraphics.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

namespace ocvmg
{

auto LoadMovieFile(const std::string& file_name)
-> mg::Color4bMovie
{
	auto capture = cv::VideoCapture(file_name.c_str());
	if(!capture.isOpened())
	{
		std::cout << "file open error!" << std::endl;	
	}

	auto movie = mg::Color4bMovie();
	
	//while(1)
	{
		auto cv_frame = cv::Mat();	
		capture >> cv_frame;
		//std::cout << cv_frame << std::endl;
		//std::cout << "width:" << cv_frame.size().width << ", height:" << cv_frame.size().height << std::endl;
		const auto frame = mg::CreateColor4bImage(
			common::Size2ui(cv_frame.size().width, cv_frame.size().height),
			[&cv_frame](const unsigned int x, const unsigned int y)
			{
				//const auto cv_color = cv_frame.at<cv::Scalar>(y, x);
				//const auto cv_color = cv_frame.at<cv::Scalar>(x, y);
				//std::cout << "x:" << x << ", y:" << y << std::endl;
				//std::cout << cv_color[2] << std::endl;
				//return mg::CreateColor4b(cv_color(2), cv_color(1), cv_color(0), 0);
				return mg::CreateColor4b(1, 2, 3, 0);
			}
		);
		movie.AddFrame(frame);
	}

	return movie;
}

}

