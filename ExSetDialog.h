#ifndef EXSETDIALOG_H
#define EXSETDIALOG_H
#include <qdialog.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qgroupbox.h>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qcheckbox.h>
#include <qcombobox.h>
#include <qtextedit.h>
#include <qvalidator.h>
#include <qvector.h>
#include "State.h"
#include "BV.h"
#include "Contr.h"
#include "BV_ot_do_class.h"
#include "Action_CD.h"

class ExchangeSetDialog :public QDialog
{
	Q_OBJECT
public:
	ExchangeSetDialog(QWidget* parent = 0);
public:
	QLabel* data_word_lab;
	QLabel* BV_lab;
	QLabel* con_ex_lab;
	QTextEdit* data_word_ed;
	QVBoxLayout* main_lay;
	QVBoxLayout* up_lay;
	QGridLayout* mid_grid;
	QHBoxLayout* mid_lay;
	QPushButton* stop_btn;
	QPushButton* accept_btn;
	QVBoxLayout* down_h_lay;
	QCheckBox* join_BV_chb;
	QPushButton* back_btn;
	QVector <Contr_cl*> contr_sv;
	QVector <Act_CD*> Act_rep;
	QVector <BV_cl*> BV_s;
	QVector <BV_ot_do_class*> *BV_s_wid;
	//BV_cl* tmp_bv;
	QString tmp_Name;
	StateData* State_s;
	//int count;
public slots:
void Save_State();
void TextValidator();
void Imitation_List_add();
void Save_Act();
};
#endif // EXSETDIALOG_H

