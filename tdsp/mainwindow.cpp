#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    worker(3)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OpenMovieFile()
{
    this->movie_file_name = QFileDialog::getOpenFileName(this, tr("Open Movie File"), "./", tr("Movie Files (*.avi)"));
    this->setWindowTitle(this->movie_file_name);

    //open movie file
    auto is_open_ok = this->worker.OpenMovieFile(this->movie_file_name);
    if(is_open_ok)
    {
        this->ui->FrameSelectSlider->setEnabled(true);
        const auto length = this->worker.GetMovieLength();
        this->ui->FrameSelectSlider->setMaximum(static_cast<int>(length)-1);
        this->ui->tabWidget->setEnabled(true);
        this->SelectFrame(this->ui->FrameSelectSlider->value());
    }
}

void MainWindow::SaveMovieFile()
{
    const auto movie_file_name = QFileDialog::getSaveFileName(this, tr("Save Movie File"), "./", tr("Movie Files (*.avi)"));
    this->worker.SaveBackgroundCancelledMovie(movie_file_name);
}

void MainWindow::SelectFrame(int frame_number)
{
    this->ui->FrameNumberIndicator->setText(QString::number(frame_number));
    //change image frame
    //const auto qimage = this->worker.GetRawFrame(frame_number);
    const auto qimage = this->worker.GetBackgroundCanceledFrameAsQImage(frame_number);
    const auto qpixmap = QPixmap::fromImage(qimage);
    this->ui->ImageScreen->setPixmap(qpixmap);
}

void MainWindow::SetThreshold1()
{
    const auto threshold_min = cv::Scalar
    (
        this->ui->Threshold1SliderRedMin->value(),
        this->ui->Threshold1SliderGreenMin->value(),
        this->ui->Threshold1SliderBlueMin->value()
    );

    const auto threshold_max = cv::Scalar
    (
        this->ui->Threshold1SliderRedMax->value(),
        this->ui->Threshold1SliderGreenMax->value(),
        this->ui->Threshold1SliderBlueMax->value()
    );

    this->worker.SetBackgroudCancelingFilter(0, threshold_min, threshold_max);
    this->SelectFrame(this->ui->FrameSelectSlider->value());
}

void MainWindow::SetThreshold2()
{
    const auto threshold_min = cv::Scalar
    (
        this->ui->Threshold2SliderRedMin->value(),
        this->ui->Threshold2SliderGreenMin->value(),
        this->ui->Threshold2SliderBlueMin->value()
    );

    const auto threshold_max = cv::Scalar
    (
        this->ui->Threshold2SliderRedMax->value(),
        this->ui->Threshold2SliderGreenMax->value(),
        this->ui->Threshold2SliderBlueMax->value()
    );

    this->worker.SetBackgroudCancelingFilter(1, threshold_min, threshold_max);
    this->SelectFrame(this->ui->FrameSelectSlider->value());
}

void MainWindow::SetThreshold3()
{
    const auto threshold_min = cv::Scalar
    (
        this->ui->Threshold3SliderRedMin->value(),
        this->ui->Threshold3SliderGreenMin->value(),
        this->ui->Threshold3SliderBlueMin->value()
    );

    const auto threshold_max = cv::Scalar
    (
        this->ui->Threshold3SliderRedMax->value(),
        this->ui->Threshold3SliderGreenMax->value(),
        this->ui->Threshold3SliderBlueMax->value()
    );

    this->worker.SetBackgroudCancelingFilter(2, threshold_min, threshold_max);
    this->SelectFrame(this->ui->FrameSelectSlider->value());
}
