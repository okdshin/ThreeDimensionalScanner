#ifndef MIDDLEWORKER_H
#define MIDDLEWORKER_H
#include <vector>
#include <tuple>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QImage>
#include <QString>

class MiddleWorker
{
public:
    MiddleWorker(unsigned int filter_num);
    auto OpenMovieFile(const QString& file_name) -> bool;
    auto GetMovieLength() -> unsigned int;
    auto GetRawFrame(unsigned int frame_index) -> QImage;
    auto GetBackgroundCanceledFrame(unsigned int frame_index) -> cv::Mat;
    auto GetBackgroundCanceledFrameAsQImage(unsigned int frame_index) -> QImage;
    auto SetBackgroudCancelingFilter(unsigned int filter_index, const cv::Scalar& min_color, const cv::Scalar& max_color) -> void;
    auto SaveBackgroundCancelledMovie(const QString& file_name) -> void;

private:
    std::vector<std::tuple<cv::Scalar, cv::Scalar>> filter_list;
    std::vector<cv::Mat> frame_list;
};

#endif // MIDDLEWORKER_H
