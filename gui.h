#ifndef GUI_H
#define GUI_H
#include <qdialog.h>
#include <qboxlayout.h>
#include <qgridlayout.h>
#include "AbWidg.h"
#include <qmap.h>

class FirstClass : public QWidget
{
	Q_OBJECT
public:
	const int raz = 18;
	FirstClass(QWidget* parent = 0);
public slots:
	void add_new_widg();
	void delete_this_abnt();
private:
	QGridLayout* main_lay;
	QMap<int, QWidget*> WMap;
	int count = 0;
};
#endif // GUI_H
