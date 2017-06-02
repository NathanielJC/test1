#include "Dialog_val.h"
#include "windows.h"
#include "qstring.h"

Control_Dialog::Control_Dialog(QWidget* parent) : QDialog(parent)
{
	QVBoxLayout* main_lay = new QVBoxLayout(this);
	QGridLayout* gr_lay = new QGridLayout(this);
	QHBoxLayout* down_lay = new QHBoxLayout(this);
	Adress_lab = new QLabel(this);
	Adress_ed = new QLineEdit(this);
	Subadress_lab = new QLabel(this);
	Subadress_ed = new QLineEdit(this);
	CD_count_lab = new QLabel(this);
	CD_count_ed = new QLineEdit(this);
	CD_lab = new QLabel(this);
	CD_ed = new QTextEdit(this);
	Accept_btn = new QPushButton(this);
	Cancel_btn = new QPushButton(this);

	this->setMaximumHeight(225);
	this->setMinimumHeight(225);
	this->setMinimumWidth(320);
	this->setMaximumWidth(320);
	CD_ed->setMinimumWidth(290);
	CD_ed->setMaximumWidth(290);
	CD_ed->setMaximumHeight(70);
	Adress_ed->setMaxLength(2);
	Subadress_ed->setMaxLength(2);
	CD_count_ed->setMaxLength(2);
	CD_count_ed->setMaximumWidth(20);
	Adress_ed->setMaximumWidth(20);
	Subadress_ed->setMaximumWidth(20);

	gr_lay->addWidget(Adress_ed, 2, 1,Qt::AlignHCenter);
	gr_lay->addWidget(Adress_lab, 1, 1,Qt::AlignHCenter);
	gr_lay->addWidget(Subadress_lab, 1, 2, Qt::AlignHCenter);
	gr_lay->addWidget(Subadress_ed, 2, 2,Qt::AlignHCenter);
	gr_lay->addWidget(CD_count_lab, 1, 3, Qt::AlignHCenter);
	gr_lay->addWidget(CD_count_ed, 2, 3,Qt::AlignHCenter);
	main_lay->addLayout(gr_lay);
	main_lay->addWidget(CD_lab,0, Qt::AlignHCenter);
	main_lay->addWidget(CD_ed,0,Qt::AlignHCenter);
	down_lay->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	down_lay->addWidget(Cancel_btn);
	down_lay->addWidget(Accept_btn);
	main_lay->addLayout(down_lay);

	QIcon icon;
	icon.addFile(":img/ok.png");
	Accept_btn->setIcon(icon);
	icon.addFile(":img/cancel.png");
	Cancel_btn->setIcon(icon);

	Adress_lab->setText("Адрес");
	Subadress_lab->setText("Подадрес");
	CD_count_lab->setText("Количество СД");
	CD_lab->setText("Слова данных");

	Adress_ed->setInputMask("99");
	Subadress_ed->setInputMask("99");
	CD_count_ed->setInputMask("99");

	QFont NewFont("Courier New", 8);
	CD_ed->setFont(NewFont);

	message_cl message_m;
	//QVector <unsigned short> tmp_vec;
	//message_cl message_m(Adress_ed->text().toInt(), Subadress_ed->text().toInt(), tmp_vec);



	connect(CD_ed, &QTextEdit::textChanged, this, &Control_Dialog::check_CD);
	connect(Adress_ed, &QLineEdit::textChanged, this, &Control_Dialog::check_ed);
	connect(Subadress_ed, &QLineEdit::textChanged, this, &Control_Dialog::check_ed);
	connect(CD_count_ed, &QLineEdit::textChanged, this, &Control_Dialog::check_ed);
	connect(Accept_btn, &QPushButton::clicked, this, &Control_Dialog::sv_ms);
	connect(Cancel_btn, &QPushButton::clicked, this, &QDialog::reject);
	connect(Accept_btn, &QPushButton::clicked, this, &QDialog::accept);
}

void Control_Dialog::renew()
{
	Adress_ed->setText(QString::number(message_m.adress));
	Subadress_ed->setText(QString::number(message_m.subadress));
	CD_count_ed->setText(QString::number(message_m.CD.count()));
	CD_ed->setPlainText(message_m.form_string_sd());
}

void Control_Dialog::sv_ms()
{
	//QVector <unsigned short> CD_complete;
	//QString CD_text = CD_ed->toPlainText();
	//QRegExp reg("[\\s]");
	//QStringList Stlist = CD_text.split(QRegExp("\\s+"));
	//CD_text.replace(reg, ",");
	//int tmp_int = CD_text.count() / 4;
	//for (int i = 0; i < tmp_int; i++)
	//{
	//	unsigned short tmp_short;
	//	bool flag;
	//	tmp_short = Stlist.value(i).toUShort(&flag, 16);
	//	CD_complete.push_back(tmp_short);
	//}
	QVector <unsigned short> CD_complete;
	QStringList tmp_str;
	tmp_str = CD_ed->toPlainText().split(" ");
	for (int i = 0; i < tmp_str.count(); i++)
	{
		unsigned short tmp_short;
		bool flag;
		tmp_short = tmp_str[i].toUShort(&flag, 16);
		CD_complete.push_back(tmp_short);
	}
	message_m.message_set_data(Adress_ed->text().toInt(), Subadress_ed->text().toInt(), CD_complete);
	//message_m(adress->text().toInt(), subadress->text().toInt(), CD_com);
}

void Control_Dialog::check_CD()
{
	ActivateKeyboardLayout((HKL)MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT), KLF_SETFORPROCESS);
	QString new_text = CD_ed->toPlainText().toUpper();
	int size;
	QString size_s;
	size_s = CD_count_ed->text();
	size = size_s.QString::toInt();
	if (new_text.size() > size * 5 - 1)
		new_text.remove(size * 5 - 1, new_text.size() - size * 4 );
	new_text.replace(QRegExp("[^A-F0-9]"), "");
	QStringList em_sp;
	for (int i = 0; i < new_text.length(); i += 4)
		em_sp << new_text.mid(i, 4);
	QStringList tab_sp;
	CD_ed->blockSignals(true);
	CD_ed->setText(em_sp.join(" "));
	if (new_text.size() < size * 5 - 1)
		CD_ed->moveCursor(QTextCursor::EndOfBlock);
	CD_ed->blockSignals(false);
}
void Control_Dialog::check_ed()
{
		int i = 32;
		int f;
		QString str;
		str = Adress_ed->text();
		f = str.QString::toInt();
		if (i-2 <= f)
			Adress_ed->setText("30");
		if (f < 1 & Adress_ed->text() != NULL)
			Adress_ed->setText("1");
		str = Subadress_ed->text();
		f = str.QString::toInt();
		if (i-1 <= f)
			Subadress_ed->setText("31");
		if (f < 1 & Subadress_ed->text() != NULL)
			Subadress_ed->setText("0");
		str = CD_count_ed->text();
		f = str.QString::toInt();
		if (i <= f)
			CD_count_ed->setText("32");
		if (f < 1 & CD_count_ed->text() != NULL)
			CD_count_ed->setText("1");
}
//void ConvertToVector(QVector <unsigned short> CD_con, QString CD_text)
//{
//	//QString CD_R;
//	QRegExp reg("[\\s]");
//	QStringList Stlist = CD_text.split(QRegExp("\\s+"));
//	//QString CD = sh.CD_ed->toPlainText();
//	CD_text.replace(reg, ",");
//	int tmp_int = CD_text.count / 4;
//	//CD_R = sh.CD_ed->toPlainText();
//	//int tmp_int = sh.CD_count_ed->text().toInt();
//	//QVector <unsigned short> tmp_vec;
//	for (int i = 0; i < tmp_int; i++)
//	{
//	    unsigned short tmp_short;
//		bool flag;
//		tmp_short = Stlist.value(i).toUShort(&flag, 16);
//		CD_con.push_back(tmp_short);
//	}
//	//contr_data->message_m.CD = tmp_vec;
//	//action_ed->setText(contr_data->message_m.form_string_all());
//}
//void Control_Dialog::set_data(int adr, int subadr, QVector<unsigned short> CD)
//void Control_Dialog::set_data()
//{
//	
//	Adress_ed->setText(QString::number(adr));
//	Subadress_ed->setText(QString::number (subadr));
//	CD_count_ed->setText(QString::number(CD.count()));
//	QString CD_text;
//	for (int i; i < CD.count(); i++)
//	{
//		CD_text = CD_text + CD.value(i) + " ";
//	}
//	CD_ed->setPlainText(CD_text);
//}
//void Control_Dialog::get_data()// В классе!!!!!!
//{
//
//}
