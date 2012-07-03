/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jul 3 11:24:52 2012
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionQuit;
    QAction *actionExportMaskedMovie;
    QAction *actionExportAsMMM;
    QAction *actionImportFromMMMFile;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QSlider *red_min_slider;
    QSlider *red_max_slider;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QSlider *green_max_slider;
    QSlider *green_min_slider;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_6;
    QSlider *blue_max_slider;
    QSlider *blue_min_slider;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QSlider *red_min_slider_2;
    QSlider *red_max_slider_2;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_9;
    QSlider *green_max_slider_2;
    QSlider *green_min_slider_2;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_8;
    QSlider *blue_max_slider_2;
    QSlider *blue_min_slider_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_14;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_13;
    QSlider *red_min_slider_3;
    QSlider *red_max_slider_3;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_11;
    QSlider *green_max_slider_3;
    QSlider *green_min_slider_3;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_12;
    QSlider *blue_max_slider_3;
    QSlider *blue_min_slider_3;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(546, 371);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionExportMaskedMovie = new QAction(MainWindow);
        actionExportMaskedMovie->setObjectName(QString::fromUtf8("actionExportMaskedMovie"));
        actionExportMaskedMovie->setEnabled(true);
        actionExportAsMMM = new QAction(MainWindow);
        actionExportAsMMM->setObjectName(QString::fromUtf8("actionExportAsMMM"));
        actionImportFromMMMFile = new QAction(MainWindow);
        actionImportFromMMMFile->setObjectName(QString::fromUtf8("actionImportFromMMMFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(320, 240));
        label->setBaseSize(QSize(320, 240));
        label->setScaledContents(false);

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setBaseSize(QSize(320, 0));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_3->addLayout(horizontalLayout);

        verticalWidget_2 = new QWidget(centralWidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(verticalWidget_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setBaseSize(QSize(320, 240));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_4 = new QVBoxLayout(tab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setFlat(false);
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        red_min_slider = new QSlider(groupBox);
        red_min_slider->setObjectName(QString::fromUtf8("red_min_slider"));
        red_min_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(red_min_slider->sizePolicy().hasHeightForWidth());
        red_min_slider->setSizePolicy(sizePolicy2);
        red_min_slider->setMaximum(255);
        red_min_slider->setValue(127);
        red_min_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(red_min_slider);

        red_max_slider = new QSlider(groupBox);
        red_max_slider->setObjectName(QString::fromUtf8("red_max_slider"));
        red_max_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(red_max_slider->sizePolicy().hasHeightForWidth());
        red_max_slider->setSizePolicy(sizePolicy2);
        red_max_slider->setMaximum(255);
        red_max_slider->setValue(255);
        red_max_slider->setSliderPosition(255);
        red_max_slider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(red_max_slider);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        green_max_slider = new QSlider(groupBox_2);
        green_max_slider->setObjectName(QString::fromUtf8("green_max_slider"));
        green_max_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(green_max_slider->sizePolicy().hasHeightForWidth());
        green_max_slider->setSizePolicy(sizePolicy2);
        green_max_slider->setMaximum(255);
        green_max_slider->setValue(128);
        green_max_slider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(green_max_slider);

        green_min_slider = new QSlider(groupBox_2);
        green_min_slider->setObjectName(QString::fromUtf8("green_min_slider"));
        green_min_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(green_min_slider->sizePolicy().hasHeightForWidth());
        green_min_slider->setSizePolicy(sizePolicy2);
        green_min_slider->setMaximum(255);
        green_min_slider->setValue(255);
        green_min_slider->setSliderPosition(255);
        green_min_slider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(green_min_slider);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        verticalLayout_6 = new QVBoxLayout(groupBox_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        blue_max_slider = new QSlider(groupBox_3);
        blue_max_slider->setObjectName(QString::fromUtf8("blue_max_slider"));
        blue_max_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(blue_max_slider->sizePolicy().hasHeightForWidth());
        blue_max_slider->setSizePolicy(sizePolicy2);
        blue_max_slider->setMaximum(255);
        blue_max_slider->setValue(128);
        blue_max_slider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(blue_max_slider);

        blue_min_slider = new QSlider(groupBox_3);
        blue_min_slider->setObjectName(QString::fromUtf8("blue_min_slider"));
        blue_min_slider->setEnabled(true);
        sizePolicy2.setHeightForWidth(blue_min_slider->sizePolicy().hasHeightForWidth());
        blue_min_slider->setSizePolicy(sizePolicy2);
        blue_min_slider->setMaximum(255);
        blue_min_slider->setValue(255);
        blue_min_slider->setSliderPosition(255);
        blue_min_slider->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(blue_min_slider);


        verticalLayout_4->addWidget(groupBox_3);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_10 = new QVBoxLayout(tab_2);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy2.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy2);
        groupBox_4->setFlat(false);
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        red_min_slider_2 = new QSlider(groupBox_4);
        red_min_slider_2->setObjectName(QString::fromUtf8("red_min_slider_2"));
        red_min_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(red_min_slider_2->sizePolicy().hasHeightForWidth());
        red_min_slider_2->setSizePolicy(sizePolicy2);
        red_min_slider_2->setMaximum(255);
        red_min_slider_2->setValue(127);
        red_min_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(red_min_slider_2);

        red_max_slider_2 = new QSlider(groupBox_4);
        red_max_slider_2->setObjectName(QString::fromUtf8("red_max_slider_2"));
        red_max_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(red_max_slider_2->sizePolicy().hasHeightForWidth());
        red_max_slider_2->setSizePolicy(sizePolicy2);
        red_max_slider_2->setMaximum(255);
        red_max_slider_2->setValue(255);
        red_max_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(red_max_slider_2);


        verticalLayout_10->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(tab_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        sizePolicy2.setHeightForWidth(groupBox_6->sizePolicy().hasHeightForWidth());
        groupBox_6->setSizePolicy(sizePolicy2);
        verticalLayout_9 = new QVBoxLayout(groupBox_6);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        green_max_slider_2 = new QSlider(groupBox_6);
        green_max_slider_2->setObjectName(QString::fromUtf8("green_max_slider_2"));
        green_max_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(green_max_slider_2->sizePolicy().hasHeightForWidth());
        green_max_slider_2->setSizePolicy(sizePolicy2);
        green_max_slider_2->setMaximum(255);
        green_max_slider_2->setValue(128);
        green_max_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(green_max_slider_2);

        green_min_slider_2 = new QSlider(groupBox_6);
        green_min_slider_2->setObjectName(QString::fromUtf8("green_min_slider_2"));
        green_min_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(green_min_slider_2->sizePolicy().hasHeightForWidth());
        green_min_slider_2->setSizePolicy(sizePolicy2);
        green_min_slider_2->setMaximum(255);
        green_min_slider_2->setValue(255);
        green_min_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(green_min_slider_2);


        verticalLayout_10->addWidget(groupBox_6);

        groupBox_5 = new QGroupBox(tab_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        sizePolicy2.setHeightForWidth(groupBox_5->sizePolicy().hasHeightForWidth());
        groupBox_5->setSizePolicy(sizePolicy2);
        verticalLayout_8 = new QVBoxLayout(groupBox_5);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        blue_max_slider_2 = new QSlider(groupBox_5);
        blue_max_slider_2->setObjectName(QString::fromUtf8("blue_max_slider_2"));
        blue_max_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(blue_max_slider_2->sizePolicy().hasHeightForWidth());
        blue_max_slider_2->setSizePolicy(sizePolicy2);
        blue_max_slider_2->setMaximum(255);
        blue_max_slider_2->setValue(128);
        blue_max_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(blue_max_slider_2);

        blue_min_slider_2 = new QSlider(groupBox_5);
        blue_min_slider_2->setObjectName(QString::fromUtf8("blue_min_slider_2"));
        blue_min_slider_2->setEnabled(true);
        sizePolicy2.setHeightForWidth(blue_min_slider_2->sizePolicy().hasHeightForWidth());
        blue_min_slider_2->setSizePolicy(sizePolicy2);
        blue_min_slider_2->setMaximum(255);
        blue_min_slider_2->setValue(255);
        blue_min_slider_2->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(blue_min_slider_2);


        verticalLayout_10->addWidget(groupBox_5);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        verticalLayout_14 = new QVBoxLayout(tab_3);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        groupBox_9 = new QGroupBox(tab_3);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        sizePolicy2.setHeightForWidth(groupBox_9->sizePolicy().hasHeightForWidth());
        groupBox_9->setSizePolicy(sizePolicy2);
        groupBox_9->setFlat(false);
        verticalLayout_13 = new QVBoxLayout(groupBox_9);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        red_min_slider_3 = new QSlider(groupBox_9);
        red_min_slider_3->setObjectName(QString::fromUtf8("red_min_slider_3"));
        sizePolicy2.setHeightForWidth(red_min_slider_3->sizePolicy().hasHeightForWidth());
        red_min_slider_3->setSizePolicy(sizePolicy2);
        red_min_slider_3->setMaximum(255);
        red_min_slider_3->setValue(127);
        red_min_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_13->addWidget(red_min_slider_3);

        red_max_slider_3 = new QSlider(groupBox_9);
        red_max_slider_3->setObjectName(QString::fromUtf8("red_max_slider_3"));
        sizePolicy2.setHeightForWidth(red_max_slider_3->sizePolicy().hasHeightForWidth());
        red_max_slider_3->setSizePolicy(sizePolicy2);
        red_max_slider_3->setMaximum(255);
        red_max_slider_3->setValue(255);
        red_max_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_13->addWidget(red_max_slider_3);


        verticalLayout_14->addWidget(groupBox_9);

        groupBox_7 = new QGroupBox(tab_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        sizePolicy2.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy2);
        verticalLayout_11 = new QVBoxLayout(groupBox_7);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        green_max_slider_3 = new QSlider(groupBox_7);
        green_max_slider_3->setObjectName(QString::fromUtf8("green_max_slider_3"));
        sizePolicy2.setHeightForWidth(green_max_slider_3->sizePolicy().hasHeightForWidth());
        green_max_slider_3->setSizePolicy(sizePolicy2);
        green_max_slider_3->setMaximum(255);
        green_max_slider_3->setValue(128);
        green_max_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(green_max_slider_3);

        green_min_slider_3 = new QSlider(groupBox_7);
        green_min_slider_3->setObjectName(QString::fromUtf8("green_min_slider_3"));
        sizePolicy2.setHeightForWidth(green_min_slider_3->sizePolicy().hasHeightForWidth());
        green_min_slider_3->setSizePolicy(sizePolicy2);
        green_min_slider_3->setMaximum(255);
        green_min_slider_3->setValue(255);
        green_min_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_11->addWidget(green_min_slider_3);


        verticalLayout_14->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(tab_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        sizePolicy2.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy2);
        verticalLayout_12 = new QVBoxLayout(groupBox_8);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        blue_max_slider_3 = new QSlider(groupBox_8);
        blue_max_slider_3->setObjectName(QString::fromUtf8("blue_max_slider_3"));
        sizePolicy2.setHeightForWidth(blue_max_slider_3->sizePolicy().hasHeightForWidth());
        blue_max_slider_3->setSizePolicy(sizePolicy2);
        blue_max_slider_3->setMaximum(255);
        blue_max_slider_3->setValue(128);
        blue_max_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(blue_max_slider_3);

        blue_min_slider_3 = new QSlider(groupBox_8);
        blue_min_slider_3->setObjectName(QString::fromUtf8("blue_min_slider_3"));
        sizePolicy2.setHeightForWidth(blue_min_slider_3->sizePolicy().hasHeightForWidth());
        blue_min_slider_3->setSizePolicy(sizePolicy2);
        blue_min_slider_3->setMaximum(255);
        blue_min_slider_3->setValue(255);
        blue_min_slider_3->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(blue_min_slider_3);


        verticalLayout_14->addWidget(groupBox_8);

        tabWidget->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addWidget(verticalWidget_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 546, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionImportFromMMMFile);
        menuFile->addAction(actionExportAsMMM);
        menuFile->addAction(actionExportMaskedMovie);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), MainWindow, SLOT(OpenMovieFile()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(Show(int)));
        QObject::connect(red_min_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedLower(int)));
        QObject::connect(blue_max_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueLower(int)));
        QObject::connect(blue_min_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueHigher(int)));
        QObject::connect(green_max_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenLower(int)));
        QObject::connect(green_min_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenHigher(int)));
        QObject::connect(red_max_slider, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedHigher(int)));
        QObject::connect(red_min_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedLower(int)));
        QObject::connect(red_max_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedHigher(int)));
        QObject::connect(green_max_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenLower(int)));
        QObject::connect(green_min_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenHigher(int)));
        QObject::connect(blue_max_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueLower(int)));
        QObject::connect(blue_min_slider_2, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueHigher(int)));
        QObject::connect(tabWidget, SIGNAL(currentChanged(int)), MainWindow, SLOT(ChangeThresholdFilter(int)));
        QObject::connect(red_min_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedLower(int)));
        QObject::connect(red_max_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1RedHigher(int)));
        QObject::connect(green_max_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenLower(int)));
        QObject::connect(green_min_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1GreenHigher(int)));
        QObject::connect(blue_max_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueLower(int)));
        QObject::connect(blue_min_slider_3, SIGNAL(valueChanged(int)), MainWindow, SLOT(ChangeThreshold1BlueHigher(int)));
        QObject::connect(actionExportMaskedMovie, SIGNAL(triggered()), MainWindow, SLOT(ExportMaskedMovieFile()));
        QObject::connect(actionExportAsMMM, SIGNAL(triggered()), MainWindow, SLOT(ExportAsMmmFile()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionExportMaskedMovie->setText(QApplication::translate("MainWindow", "ExportMaskedMovie", 0, QApplication::UnicodeUTF8));
        actionExportAsMMM->setText(QApplication::translate("MainWindow", "ExportAsMMM", 0, QApplication::UnicodeUTF8));
        actionImportFromMMMFile->setText(QApplication::translate("MainWindow", "ImportFromMMMFile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "No Movie Loaded.", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "RGB1", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "RGB2", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "RGB3", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
