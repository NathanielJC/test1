#ifndef DIALOG_VAL_H
#define DIALOG_VAL_H
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qboxlayout.h>
#include <qdialog.h>
#include <qvector.h>
#include "message.h"

class Control_Dialog : public QDialog
{
	Q_OBJECT
public:
	Control_Dialog(QWidget* parent = 0);
public:
	QLabel* Adress_lab;
	QLabel* Subadress_lab;
	QLabel* CD_count_lab;
	QLabel* CD_lab;
	QLineEdit* Subadress_ed;
	QLineEdit* Adress_ed;
	QLineEdit* CD_count_ed;
	QTextEdit* CD_ed;
	QPushButton* Accept_btn;
	QPushButton* Cancel_btn;
	//QVector <unsigned short> CD_complete;
	message_cl message_m;
	void renew();
public slots: 
    //void set_data(int adr, int subadr, QVector<unsigned short> CD);
 //   void set_data();
	//void get_data();
	//void ConvertToVector(QVector <unsigned short> CD_con, QString CD_text);
	void check_CD();
	void check_ed();
	void sv_ms();
    //void set_data();
};

#endif //DIALOG_VAL_H