#pragma once
#include <QtGui>
#include "MovieLoader.h"

class PickupConverter : public QWidget//QMainWindow
{
	Q_OBJECT
public:
	PickupConverter();
	~PickupConverter();

private slots:
	void Open();
	void Show(int frame_number);

private:
	void CreateActions();
	void CreateMenus();
	/*void AdjustScrollBar(QScrollBar* scroll_bar, double factor)*/

	QLabel* image_label;
	QScrollArea* scroll_area;

	QAction* open_act;
	QMenu* file_menu;

	QSlider* slider;

	QVBoxLayout* main_layout;

	fmv::MovieLoader movie_loader;

};
