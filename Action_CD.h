#ifndef ACTION_CD_H
#define ACTION_CD_H
#include <qwidget.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qvector.h>
#include "Contr.h"

class Act_CD : public QWidget
{
	Q_OBJECT
public:
	Act_CD(QWidget* parent = 0);
public:
	QLineEdit* action_ed;
	QComboBox* action_cbox;
	QPushButton* Val_btn;
	Contr_cl* contr_data;//Хранение
public slots:
	void Check_action_ed();
	void Check_combobox();
	//message_cl Split_Edit(QString Spl_ed);
};
#endif //ACTION_CD_H