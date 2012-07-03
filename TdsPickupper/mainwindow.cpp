#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Routine.h"
#include <opencv2/opencv.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    pickupper(3),
    current_frame_number(0),
    current_filter_id(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
void mouseMoveEvent(QMouseEvent* event)
{
    QPointF p = mapToScene( event->pos() );
    QRgb rgb = this
            .pixel( p.x(),p.y() );
}*/

void MainWindow::OpenMovieFile()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
    if(!file_name.isEmpty())
    {
        this->pickupper.Load(ConvertQStringToStdString(file_name));
        auto movie_size = this->pickupper.GetMovieLength();
        this->ui->horizontalSlider->setMaximum(movie_size);
        this->Show(0);

        this->ui->horizontalSlider->setEnabled(true);
        this->ui->tabWidget->setEnabled(true);
    }
}

void MainWindow::ExportMaskedMovieFile()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("Export Masked Movie File"), QDir::currentPath());
    if(!file_name.isEmpty())
    {
        this->pickupper.ExportMaskedMovie(ConvertQStringToStdString(file_name));
    }
    else
    {
        std::cout << "cansel" << std::endl;
    }
}
/*
void MainWindow::ImportFromMmmFile()
{
    QString file_name = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());
    if(!file_name.isEmpty())
    {
        this->pickupper.Load(ConvertQStringToStdString(file_name));
        auto movie_size = this->pickupper.GetMovieLength();
        this->ui->horizontalSlider->setMaximum(movie_size);
        this->Show(0);

        this->ui->horizontalSlider->setEnabled(true);
        this->ui->tabWidget->setEnabled(true);
    }
}
*/
void MainWindow::ExportAsMmmFile()
{
    QString file_name = QFileDialog::getSaveFileName(this, tr("Export MMM File"), QDir::currentPath());
    if(!file_name.isEmpty())
    {
        this->pickupper.ExportAsMmmFile(ConvertQStringToStdString(file_name));
    }
    else
    {
        std::cout << "cansel" << std::endl;
    }
}
void MainWindow::Show(int frame_number)
{
    this->SetCurrentFrameNumber(frame_number);
    this->DoShow();
}

void MainWindow::SetCurrentFrameNumber(int frame_number)
{
    this->current_frame_number = frame_number;
}

void MainWindow::DoShow()
{
    QImage image = ConvertIplImageToQImage(this->pickupper.GetMaskedFrame(this->current_frame_number));//QImage(file_name);

    if(image.isNull())
    {
        QMessageBox::information(this, tr("Pickup Converter"), tr("Cannot load %1.").arg("image"));
        return;
    }
    else
    {
        QPixmap pixmap = QPixmap::fromImage(image);
        QPixmap scaled_pixmap = pixmap.scaled(320, 240, Qt::KeepAspectRatio, Qt::FastTransformation);
        this->ui->label->setPixmap(scaled_pixmap);
        //this->ui->label->setPixmap(pixmap);
        this->ui->label->adjustSize();
    }
}

void MainWindow::ChangeThreshold1RedLower(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdLower(this->current_filter_id, 2, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThreshold1GreenLower(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdLower(this->current_filter_id, 1, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThreshold1BlueLower(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdLower(this->current_filter_id, 0, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThreshold1RedHigher(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdHigher(this->current_filter_id, 2, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThreshold1GreenHigher(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdHigher(this->current_filter_id, 1, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThreshold1BlueHigher(int value)
{
    std::cout << value << std::endl;
    this->pickupper.SetMaskThresholdHigher(this->current_filter_id, 0, static_cast<unsigned char>(value));
    this->Show(this->current_frame_number);
}

void MainWindow::ChangeThresholdFilter(int index)
{
    std::cout << "tab index:" << index << std::endl;
    this->current_filter_id = index;
}

