#ifdef UNIT_TEST
#include "MovieLoader.h"

using namespace ocv;

int main()
{
	auto movie_loader = MovieLoader();
	movie_loader.Load("sample.avi");
	cv::namedWindow("frame", CV_WINDOW_AUTOSIZE | CV_WINDOW_FREERATIO);
	auto frame_image = movie_loader.GetFrame(50);
	cv::imshow("frame", frame_image);

	return 0;
}

#endif
