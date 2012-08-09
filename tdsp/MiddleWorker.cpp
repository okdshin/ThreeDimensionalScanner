#include "MiddleWorker.h"
#include <cassert>
#include <utility>
#include <tuple>
#include <QRgb>

MiddleWorker::MiddleWorker(unsigned int filter_num) : filter_list(filter_num), frame_list()
{
    for(auto& filter : filter_list)
    {
        filter = std::make_tuple(cv::Scalar(127,127,127), cv::Scalar(127,127,127));
    }
}

auto MiddleWorker::OpenMovieFile(const QString& file_name)
->bool
{
    auto cap = cv::VideoCapture(file_name.toStdString());
    // ファイルがオープンできたかの確認
    if(!cap.isOpened())
    {
        std::cout << "movie file open error." << std::endl;
        return false;
    }

    this->frame_list.clear();
    auto frame = cv::Mat();
    while(1)
    {
        cap >> frame;  // キャプチャ
        if(frame.empty())
        {
            break;
        }
        this->frame_list.push_back(frame.clone());
    }
    return true;
}

auto MiddleWorker::GetMovieLength() -> unsigned int
{
    return this->frame_list.size();
}

auto CvMatToQImage(const cv::Mat3b &src_mat)
-> QImage
{
    auto dest_qimage = QImage(src_mat.cols, src_mat.rows, QImage::Format_ARGB32);
    for (int y = 0; y < src_mat.rows; ++y)
    {
        const cv::Vec3b* src_mat_row = src_mat[y];
        auto dest_qimage_row = (QRgb*)dest_qimage.scanLine(y);
        for (int x = 0; x < src_mat.cols; ++x)
        {
                const auto r = src_mat_row[x][2];
                const auto g = src_mat_row[x][1];
                const auto b = src_mat_row[x][0];
                dest_qimage_row[x] = qRgba(r, g, b, 255);
        }
    }
    return dest_qimage;
}

auto MiddleWorker::GetRawFrame(unsigned int frame_index)
->QImage
{
    assert(frame_index < frame_list.size());
    const auto cvframe = this->frame_list[frame_index];
    const auto qimage = CvMatToQImage(cvframe);

    const auto scaled_qimage = qimage.scaled(QSize(320, 240));

    return scaled_qimage;
}

auto MiddleWorker::GetBackgroundCanceledFrame(unsigned int frame_index)
->cv::Mat
{
    assert(frame_index < frame_list.size());
    const auto cvframe = this->frame_list[frame_index];

    auto cvframe_mask = cv::Mat(cvframe.size(), CV_8UC1, cv::Scalar(1));
    for(unsigned int i = 0; i < this->filter_list.size(); ++i)
    {
        auto cvframe_mask_temp = cv::Mat();
        const auto min_scalar = std::get<0>(this->filter_list[i]);
        const auto max_scalar = std::get<1>(this->filter_list[i]);

        cv::inRange(cvframe, min_scalar, max_scalar, cvframe_mask_temp);
        auto cvframe_mask_temp_not = cv::Mat(cvframe.size(), CV_8UC1);
        cv::bitwise_not(cvframe_mask_temp, cvframe_mask_temp_not);
        cv::bitwise_and(cvframe_mask_temp_not, cvframe_mask.clone(), cvframe_mask);
    }

    auto cvframe_pickupped = cv::Mat();
    //auto cvframe_mask_not = cv::Mat(cvframe.size(), CV_8UC1);
    //cv::bitwise_not(cvframe_mask, cvframe_mask_not);
    cvframe.copyTo(cvframe_pickupped, cvframe_mask);
    return cvframe_pickupped;


}

auto MiddleWorker::GetBackgroundCanceledFrameAsQImage(unsigned int frame_index)
->QImage
{
    auto cvframe_pickupped = this->GetBackgroundCanceledFrame(frame_index);
    const auto qimage = CvMatToQImage(cvframe_pickupped);
    const auto scaled_qimage = qimage.scaled(QSize(320, 240));

    return scaled_qimage;
}

auto MiddleWorker::SetBackgroudCancelingFilter(unsigned int filter_index, const cv::Scalar& min_color, const cv::Scalar& max_color)
->void
{
    assert(filter_index < this->filter_list.size());
    this->filter_list[filter_index] = std::tuple<cv::Scalar, cv::Scalar>(min_color, max_color);
}

auto MiddleWorker::SaveBackgroundCancelledMovie(const QString& file_name) -> void
{
// ビデオライタ
    int fps = 15;
    assert(this->frame_list.empty() == false);
    auto scaled_frame = cv::Mat(240, 320, this->frame_list[0].type());
    cv::VideoWriter writer(
        file_name.toStdString(),
        CV_FOURCC('X','V','I','D'),
        fps,
        scaled_frame.size()
    );
    for(unsigned int i = 0; i < this->GetMovieLength(); ++i)
    {
        const auto frame = this->GetBackgroundCanceledFrame(i);

        cv::resize(frame, scaled_frame, scaled_frame.size());
        writer << scaled_frame;

    }
}
