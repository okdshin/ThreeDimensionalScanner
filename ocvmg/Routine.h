#pragma once
//Routine:20120709
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../mg/MiddleGraphics.h"
#include "../common/Size.h"
namespace ocvmg
{
auto ConvertCvMatToColor4bImage(const cv::Mat& cvmat)
->mg::Color4bImage
{

	return mg::CreateColor4bImage(
		common::Size2ui(cvmat.cols, cvmat.rows),
		[&cvmat](const unsigned int x, const unsigned int y)
		{
			const auto scalar = cvmat.at<cv::Vec3b>(y,x);
			const auto b = scalar[0];
			const auto g = scalar[1];
			const auto r = scalar[2];
			return mg::CreateColor4b(r, g, b, 0);
		}
	);
}

auto ConvertColor4bImageToCvMat(const mg::Color4bImage& image)
->cv::Mat
{
	const auto size = image.GetSize();
	auto dst_mat = cv::Mat(size.GetHeight(), size.GetWidth(), CV_8UC3);
	common::ForEachIndex
	(
		image.GetSize(),
		[&image, &dst_mat](const unsigned int x, const unsigned int y)
		{
			const auto color = image(x, y);
			dst_mat.at<cv::Vec3b>(y,x)[0] = color(2);
			dst_mat.at<cv::Vec3b>(y,x)[1] = color(1);
			dst_mat.at<cv::Vec3b>(y,x)[2] = color(0);
		}

	);

	return dst_mat;
		
}



}

