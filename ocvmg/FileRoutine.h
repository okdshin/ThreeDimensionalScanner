#pragma once
//FileRoutine:20120707
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include "../mg/Color4bImage.h"

namespace ocvmg
{
auto OpenImageFile(const std::string& file_name) 
->mg::Color4bImage
{
	const auto cvmat = cv::imread(file_name);
	return mg::CreateColor4bImage(
		common::Size2ui(cvmat.cols, cvmat.rows),
		[&cvmat](const unsigned int x, const unsigned int y)
		{
			const auto b = cvmat.data[y * cvmat.cols + x * cvmat.step + 0];
			const auto g = cvmat.data[y * cvmat.cols + x * cvmat.step + 1];
			const auto r = cvmat.data[y * cvmat.cols + x * cvmat.step + 2];

			return mg::CreateColor4b(r, g, b, 0);
		}
	);
}
}

