/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue Jul 17 00:46:35 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenFile;
    QAction *action_Quit;
    QAction *actionSaveFile;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *ImageScreen;
    QHBoxLayout *horizontalLayout;
    QSlider *FrameSelectSlider;
    QLabel *FrameNumberIndicator;
    QTabWidget *tabWidget;
    QWidget *threshold1_tab;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSlider *Threshold1SliderRedMin;
    QSpacerItem *verticalSpacer;
    QSlider *Threshold1SliderRedMax;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QSlider *Threshold1SliderGreenMin;
    QSpacerItem *verticalSpacer_2;
    QSlider *Threshold1SliderGreenMax;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QSlider *Threshold1SliderBlueMin;
    QSpacerItem *verticalSpacer_3;
    QSlider *Threshold1SliderBlueMax;
    QWidget *threshold2_tab;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QSlider *Threshold2SliderRedMin;
    QSpacerItem *verticalSpacer_6;
    QSlider *Threshold2SliderRedMax;
    QGroupBox *groupBox_4;
    QWidget *layoutWidget_3;
    QVBoxLayout *verticalLayout_6;
    QSlider *Threshold2SliderGreenMin;
    QSpacerItem *verticalSpacer_4;
    QSlider *Threshold2SliderGreenMax;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget_4;
    QVBoxLayout *verticalLayout_7;
    QSlider *Threshold2SliderBlueMin;
    QSpacerItem *verticalSpacer_5;
    QSlider *Threshold2SliderBlueMax;
    QWidget *threshold3_tab;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_9;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_10;
    QSlider *Threshold3SliderRedMin;
    QSpacerItem *verticalSpacer_9;
    QSlider *Threshold3SliderRedMax;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_9;
    QSlider *Threshold3SliderGreenMin;
    QSpacerItem *verticalSpacer_8;
    QSlider *Threshold3SliderGreenMax;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_8;
    QSlider *Threshold3SliderBlueMin;
    QSpacerItem *verticalSpacer_7;
    QSlider *Threshold3SliderBlueMax;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(611, 329);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        action_Quit = new QAction(MainWindow);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        actionSaveFile = new QAction(MainWindow);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_6 = new QHBoxLayout(centralWidget);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        ImageScreen = new QLabel(centralWidget);
        ImageScreen->setObjectName(QString::fromUtf8("ImageScreen"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ImageScreen->sizePolicy().hasHeightForWidth());
        ImageScreen->setSizePolicy(sizePolicy1);
        ImageScreen->setMinimumSize(QSize(320, 240));
        ImageScreen->setBaseSize(QSize(320, 240));
        ImageScreen->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(ImageScreen);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        FrameSelectSlider = new QSlider(centralWidget);
        FrameSelectSlider->setObjectName(QString::fromUtf8("FrameSelectSlider"));
        FrameSelectSlider->setEnabled(false);
        FrameSelectSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(FrameSelectSlider);

        FrameNumberIndicator = new QLabel(centralWidget);
        FrameNumberIndicator->setObjectName(QString::fromUtf8("FrameNumberIndicator"));
        sizePolicy.setHeightForWidth(FrameNumberIndicator->sizePolicy().hasHeightForWidth());
        FrameNumberIndicator->setSizePolicy(sizePolicy);
        FrameNumberIndicator->setMinimumSize(QSize(20, 0));
        FrameNumberIndicator->setWordWrap(false);

        horizontalLayout->addWidget(FrameNumberIndicator);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_2->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(false);
        threshold1_tab = new QWidget();
        threshold1_tab->setObjectName(QString::fromUtf8("threshold1_tab"));
        gridLayout = new QGridLayout(threshold1_tab);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(threshold1_tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Threshold1SliderRedMin = new QSlider(layoutWidget);
        Threshold1SliderRedMin->setObjectName(QString::fromUtf8("Threshold1SliderRedMin"));
        Threshold1SliderRedMin->setMaximum(255);
        Threshold1SliderRedMin->setValue(0);
        Threshold1SliderRedMin->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Threshold1SliderRedMin);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        Threshold1SliderRedMax = new QSlider(layoutWidget);
        Threshold1SliderRedMax->setObjectName(QString::fromUtf8("Threshold1SliderRedMax"));
        Threshold1SliderRedMax->setMaximum(255);
        Threshold1SliderRedMax->setValue(127);
        Threshold1SliderRedMax->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(Threshold1SliderRedMax);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(threshold1_tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Threshold1SliderGreenMin = new QSlider(layoutWidget1);
        Threshold1SliderGreenMin->setObjectName(QString::fromUtf8("Threshold1SliderGreenMin"));
        Threshold1SliderGreenMin->setMaximum(255);
        Threshold1SliderGreenMin->setValue(0);
        Threshold1SliderGreenMin->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(Threshold1SliderGreenMin);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        Threshold1SliderGreenMax = new QSlider(layoutWidget1);
        Threshold1SliderGreenMax->setObjectName(QString::fromUtf8("Threshold1SliderGreenMax"));
        Threshold1SliderGreenMax->setMaximum(255);
        Threshold1SliderGreenMax->setValue(127);
        Threshold1SliderGreenMax->setOrientation(Qt::Horizontal);

        verticalLayout_4->addWidget(Threshold1SliderGreenMax);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_3 = new QGroupBox(threshold1_tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        layoutWidget_2 = new QWidget(groupBox_3);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        Threshold1SliderBlueMin = new QSlider(layoutWidget_2);
        Threshold1SliderBlueMin->setObjectName(QString::fromUtf8("Threshold1SliderBlueMin"));
        Threshold1SliderBlueMin->setMaximum(255);
        Threshold1SliderBlueMin->setValue(0);
        Threshold1SliderBlueMin->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(Threshold1SliderBlueMin);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        Threshold1SliderBlueMax = new QSlider(layoutWidget_2);
        Threshold1SliderBlueMax->setObjectName(QString::fromUtf8("Threshold1SliderBlueMax"));
        Threshold1SliderBlueMax->setMaximum(255);
        Threshold1SliderBlueMax->setValue(127);
        Threshold1SliderBlueMax->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(Threshold1SliderBlueMax);


        gridLayout->addWidget(groupBox_3, 2, 0, 1, 1);

        tabWidget->addTab(threshold1_tab, QString());
        threshold2_tab = new QWidget();
        threshold2_tab->setObjectName(QString::fromUtf8("threshold2_tab"));
        gridLayout_2 = new QGridLayout(threshold2_tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox_6 = new QGroupBox(threshold2_tab);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        layoutWidget_5 = new QWidget(groupBox_6);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        Threshold2SliderRedMin = new QSlider(layoutWidget_5);
        Threshold2SliderRedMin->setObjectName(QString::fromUtf8("Threshold2SliderRedMin"));
        Threshold2SliderRedMin->setMaximum(255);
        Threshold2SliderRedMin->setValue(0);
        Threshold2SliderRedMin->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Threshold2SliderRedMin);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        Threshold2SliderRedMax = new QSlider(layoutWidget_5);
        Threshold2SliderRedMax->setObjectName(QString::fromUtf8("Threshold2SliderRedMax"));
        Threshold2SliderRedMax->setMaximum(255);
        Threshold2SliderRedMax->setValue(127);
        Threshold2SliderRedMax->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(Threshold2SliderRedMax);


        gridLayout_2->addWidget(groupBox_6, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(threshold2_tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        layoutWidget_3 = new QWidget(groupBox_4);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_3);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Threshold2SliderGreenMin = new QSlider(layoutWidget_3);
        Threshold2SliderGreenMin->setObjectName(QString::fromUtf8("Threshold2SliderGreenMin"));
        Threshold2SliderGreenMin->setMaximum(255);
        Threshold2SliderGreenMin->setValue(0);
        Threshold2SliderGreenMin->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(Threshold2SliderGreenMin);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_4);

        Threshold2SliderGreenMax = new QSlider(layoutWidget_3);
        Threshold2SliderGreenMax->setObjectName(QString::fromUtf8("Threshold2SliderGreenMax"));
        Threshold2SliderGreenMax->setMaximum(255);
        Threshold2SliderGreenMax->setValue(127);
        Threshold2SliderGreenMax->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(Threshold2SliderGreenMax);


        gridLayout_2->addWidget(groupBox_4, 1, 0, 1, 1);

        groupBox_5 = new QGroupBox(threshold2_tab);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        layoutWidget_4 = new QWidget(groupBox_5);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_7 = new QVBoxLayout(layoutWidget_4);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        Threshold2SliderBlueMin = new QSlider(layoutWidget_4);
        Threshold2SliderBlueMin->setObjectName(QString::fromUtf8("Threshold2SliderBlueMin"));
        Threshold2SliderBlueMin->setMaximum(255);
        Threshold2SliderBlueMin->setValue(0);
        Threshold2SliderBlueMin->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(Threshold2SliderBlueMin);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_5);

        Threshold2SliderBlueMax = new QSlider(layoutWidget_4);
        Threshold2SliderBlueMax->setObjectName(QString::fromUtf8("Threshold2SliderBlueMax"));
        Threshold2SliderBlueMax->setMaximum(255);
        Threshold2SliderBlueMax->setValue(127);
        Threshold2SliderBlueMax->setOrientation(Qt::Horizontal);

        verticalLayout_7->addWidget(Threshold2SliderBlueMax);


        gridLayout_2->addWidget(groupBox_5, 2, 0, 1, 1);

        tabWidget->addTab(threshold2_tab, QString());
        threshold3_tab = new QWidget();
        threshold3_tab->setObjectName(QString::fromUtf8("threshold3_tab"));
        gridLayout_3 = new QGridLayout(threshold3_tab);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox_9 = new QGroupBox(threshold3_tab);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        layoutWidget_8 = new QWidget(groupBox_9);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_10 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        Threshold3SliderRedMin = new QSlider(layoutWidget_8);
        Threshold3SliderRedMin->setObjectName(QString::fromUtf8("Threshold3SliderRedMin"));
        Threshold3SliderRedMin->setMaximum(255);
        Threshold3SliderRedMin->setValue(0);
        Threshold3SliderRedMin->setOrientation(Qt::Horizontal);

        verticalLayout_10->addWidget(Threshold3SliderRedMin);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_9);

        Threshold3SliderRedMax = new QSlider(layoutWidget_8);
        Threshold3SliderRedMax->setObjectName(QString::fromUtf8("Threshold3SliderRedMax"));
        Threshold3SliderRedMax->setMaximum(255);
        Threshold3SliderRedMax->setValue(127);
        Threshold3SliderRedMax->setOrientation(Qt::Horizontal);

        verticalLayout_10->addWidget(Threshold3SliderRedMax);


        gridLayout_3->addWidget(groupBox_9, 0, 0, 1, 1);

        groupBox_8 = new QGroupBox(threshold3_tab);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        layoutWidget_7 = new QWidget(groupBox_8);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_9 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        Threshold3SliderGreenMin = new QSlider(layoutWidget_7);
        Threshold3SliderGreenMin->setObjectName(QString::fromUtf8("Threshold3SliderGreenMin"));
        Threshold3SliderGreenMin->setMaximum(255);
        Threshold3SliderGreenMin->setValue(0);
        Threshold3SliderGreenMin->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(Threshold3SliderGreenMin);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_8);

        Threshold3SliderGreenMax = new QSlider(layoutWidget_7);
        Threshold3SliderGreenMax->setObjectName(QString::fromUtf8("Threshold3SliderGreenMax"));
        Threshold3SliderGreenMax->setMaximum(255);
        Threshold3SliderGreenMax->setValue(127);
        Threshold3SliderGreenMax->setOrientation(Qt::Horizontal);

        verticalLayout_9->addWidget(Threshold3SliderGreenMax);


        gridLayout_3->addWidget(groupBox_8, 1, 0, 1, 1);

        groupBox_7 = new QGroupBox(threshold3_tab);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        layoutWidget_6 = new QWidget(groupBox_7);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 20, 221, 44));
        verticalLayout_8 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        Threshold3SliderBlueMin = new QSlider(layoutWidget_6);
        Threshold3SliderBlueMin->setObjectName(QString::fromUtf8("Threshold3SliderBlueMin"));
        Threshold3SliderBlueMin->setMaximum(255);
        Threshold3SliderBlueMin->setValue(0);
        Threshold3SliderBlueMin->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(Threshold3SliderBlueMin);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_7);

        Threshold3SliderBlueMax = new QSlider(layoutWidget_6);
        Threshold3SliderBlueMax->setObjectName(QString::fromUtf8("Threshold3SliderBlueMax"));
        Threshold3SliderBlueMax->setMaximum(255);
        Threshold3SliderBlueMax->setValue(127);
        Threshold3SliderBlueMax->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(Threshold3SliderBlueMax);


        gridLayout_3->addWidget(groupBox_7, 2, 0, 1, 1);

        tabWidget->addTab(threshold3_tab, QString());

        horizontalLayout_2->addWidget(tabWidget);


        horizontalLayout_6->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 611, 22));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_File->menuAction());
        menu_File->addAction(actionOpenFile);
        menu_File->addAction(actionSaveFile);
        menu_File->addSeparator();
        menu_File->addAction(action_Quit);

        retranslateUi(MainWindow);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpenFile, SIGNAL(triggered()), MainWindow, SLOT(OpenMovieFile()));
        QObject::connect(FrameSelectSlider, SIGNAL(valueChanged(int)), MainWindow, SLOT(SelectFrame(int)));
        QObject::connect(Threshold1SliderRedMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold1()));
        QObject::connect(Threshold1SliderRedMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold1()));
        QObject::connect(Threshold1SliderGreenMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold1()));
        QObject::connect(Threshold1SliderGreenMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold1()));
        QObject::connect(Threshold1SliderBlueMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold1()));
        QObject::connect(Threshold1SliderBlueMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderRedMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderRedMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderGreenMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderGreenMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderBlueMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold2SliderBlueMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold2()));
        QObject::connect(Threshold3SliderRedMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(Threshold3SliderRedMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(Threshold3SliderGreenMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(Threshold3SliderGreenMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(Threshold3SliderBlueMin, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(Threshold3SliderBlueMax, SIGNAL(valueChanged(int)), MainWindow, SLOT(SetThreshold3()));
        QObject::connect(actionSaveFile, SIGNAL(triggered()), MainWindow, SLOT(SaveMovieFile()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pickupper", 0, QApplication::UnicodeUTF8));
        actionOpenFile->setText(QApplication::translate("MainWindow", "&OpenFile", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        actionSaveFile->setText(QApplication::translate("MainWindow", "SaveFile", 0, QApplication::UnicodeUTF8));
        ImageScreen->setText(QApplication::translate("MainWindow", "No Movie Loaded", 0, QApplication::UnicodeUTF8));
        FrameNumberIndicator->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(threshold1_tab), QApplication::translate("MainWindow", "Threshold1", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(threshold2_tab), QApplication::translate("MainWindow", "Threshold2", 0, QApplication::UnicodeUTF8));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Red", 0, QApplication::UnicodeUTF8));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Green", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Blue", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(threshold3_tab), QApplication::translate("MainWindow", "Threshold3", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
