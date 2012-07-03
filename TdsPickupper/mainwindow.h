#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "FromMoviePickupper.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //void mouseMoveEvent(QMouseEvent* event);

private slots:
    void OpenMovieFile();
    void ExportMaskedMovieFile();
    void ExportAsMmmFile();

    void Show(int frame_number);

    void ChangeThreshold1RedLower(int value);
    void ChangeThreshold1GreenLower(int value);
    void ChangeThreshold1BlueLower(int value);

    void ChangeThreshold1RedHigher(int value);
    void ChangeThreshold1GreenHigher(int value);
    void ChangeThreshold1BlueHigher(int value);

    void ChangeThresholdFilter(int index);

    //void ShowRgbColorUnderMouse(QMouseEvent* event);
    /*
    void ChangeThreshold1Green(int value);
    void ChangeThreshold1Blue(int value);
    */
private:
    void SetCurrentFrameNumber(int frame_number);
    void DoShow();
    Ui::MainWindow *ui;
    fmv::FromMoviePickupper pickupper;
    CvScalar red_lower, red_higher;
    int current_frame_number;
    int current_filter_id;
    //fmv::MovieLoader pickupper;

};

#endif // MAINWINDOW_H
