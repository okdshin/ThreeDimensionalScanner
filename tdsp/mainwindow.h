#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "MiddleWorker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void OpenMovieFile();
    void SelectFrame(int frame_number);
    void SetThreshold1();
    void SetThreshold2();
    void SetThreshold3();
    void SaveMovieFile();
    
private:
    Ui::MainWindow *ui;
    QString movie_file_name;
    MiddleWorker worker;
};

#endif // MAINWINDOW_H
