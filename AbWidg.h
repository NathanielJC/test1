#ifndef WIDG_H
#define WIDG_H
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include "AbSetDialog.h"


class AbWidget : public QWidget
{
	Q_OBJECT
public:
	AbWidget(QWidget* parent = 0);
public:
	QPushButton* Settings_btn;
	QPushButton* Add_btn;
	QPushButton* Delete_btn;
	QLineEdit* Name_line;
	QCheckBox* Check_box;
	QLabel* obj_num_l;
	void set_obj_num(int _obj_num);
	int get_obj_num()
	{
		return obj_num;
	}
private:
	int obj_num;
public slots:
	void settings_btn_click();
	void check_box_click(bool box_en);
signals:
	void add_new_abnt();
	void delete_abnt();
};

#endif // WIDG_H

