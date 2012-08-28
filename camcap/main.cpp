#ifdef UNIT_TEST
#include "main.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int
main(int argc, char *argv[])
{
  cv::VideoCapture cap(1);
  // 様々な設定...
  cv::Size cap_size(640, 480);
  cap.set(CV_CAP_PROP_FRAME_WIDTH, cap_size.width);
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, cap_size.height);
  // カメラがオープンできたかの確認
  if(!cap.isOpened()) return -1;

  // ビデオライタ
  int fps = 15;
  cv::VideoWriter writer("capture.avi", CV_FOURCC('X','V','I','D'), fps, cap_size);

  cv::namedWindow("Capture", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
  cv::Mat frame;   
  while(1) {
    cap >> frame;  // キャプチャ
    
	
	writer << frame;
    cv::imshow("Capture", frame);
    if(cv::waitKey(30)>= 0) break;
  }
}

#endif
