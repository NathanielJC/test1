#ifndef SET_DL_H
#define SET_DL_H
#include <qdialog.h>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <qcheckbox.h>
#include <qlabel.h>
#include <qgroupbox.h>
#include <qwidget.h>
#include "ExSetDialog.h"

class SettingsDialog : public QDialog
{
	Q_OBJECT
public:
	SettingsDialog(QWidget* parnet = 0);
public:
	QLabel* Name_Label;
	QLabel* Adress_label;
	QLabel* Unadress_label;
	QLabel* SD_label;
	QLabel* Control_Label;
	QLineEdit* Name_Edit;
	QLineEdit* Adress_Edit;
	QLineEdit* Unadress_Edit;
	QLineEdit* SD_Edit;
	QPushButton* Stop_btn;
	QPushButton* Accept_btn;
	QLabel* Magistral;
	QLineEdit* Magistral_edit;
private:
	QVBoxLayout* sec_lay;
	QGridLayout* grid_lay;
	QVBoxLayout* sett_lay;
	QGridLayout* d_lay;
	QMap<int, QWidget*> WMap;
	int count = 0;
public slots:
    void add_new_widg();
	void delete_widg();
}; 
class StateWidget : public QWidget
{
	Q_OBJECT
public:
	StateWidget(QWidget* parent = 0);
public:
	QPushButton* Settings_settings_btn;
	QPushButton* Add_settings_btn;
	QPushButton* Delete_settings_btn;
	QLineEdit* Name_settings_line;
	QLabel* obj_num_l;
	void set_obj_num(int _obj_num);
	int get_obj_num()
	{
		return obj_num;
	}
	QVector <StateData*> state_data; //TODO Хранить здесь все необходимые данные (то что уходит в окно настроек ExchangeSetDialog)
private:
	int obj_num;
signals:
	void add_new_state();
	void delete_state();
public slots:
	void settings_btn_click();
};
#endif // SET_DL_H