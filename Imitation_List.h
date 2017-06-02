#ifndef IMITATION_LIST_H
#define IMITATION_LIST_H
#include <qdialog.h>
#include <qlabel.h>
#include <qlineedit.h>
#include <qcombobox.h>
#include <qpushbutton.h>
#include <qgridlayout.h>
#include "Contr.h"
#include "Action_CD.h"

class Imitation_List : public QDialog
{
	Q_OBJECT
public:
	Imitation_List(QWidget* parent = 0);
public:
	QLabel* one_row;
	QLabel* two_row;
	QVBoxLayout* main_lay;
	QVector <Contr_cl*> Contr_cl_h;//Хранение
	QVector <Act_CD*> Act_CD_vec;//Хранение
	//QVector <Act_CD*> *Act_Cd_save;
	void set_imit_list(QVector <Contr_cl*> Contrl_cl_h);
	//QVector <Act_CD> Act_arr;//Вектор хранения динамически создаваемых Act_Cd 
public slots:
void save_data();
};

#endif //IMITATION_LIST.H