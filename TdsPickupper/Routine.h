#pragma once
#include <QString>
#include <QImage>
#include <opencv2/opencv.hpp>

std::string ConvertQStringToStdString(const QString& q_string);
QImage ConvertIplImageToQImage(IplImage *iplImg);
QImage FiltThreshold(const QImage& image);
