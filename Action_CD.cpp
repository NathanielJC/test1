#include "Action_CD.h"
#include "Dialog_val.h"

Act_CD::Act_CD(QWidget* parent) : QWidget(parent)
{
	action_ed = new QLineEdit(this);
	action_cbox = new QComboBox(this); 
	Val_btn = new QPushButton(this);
	QHBoxLayout* l_lay = new QHBoxLayout(this);
	QIcon icon;

	l_lay->addWidget(action_ed);
	l_lay->addWidget(Val_btn);
	l_lay->addWidget(action_cbox);

	action_ed->setReadOnly(true);
	action_ed->setMinimumWidth(110);
	action_cbox->addItem("Запуск имитации");
	action_cbox->addItem("Отключение имитации");

	icon.addFile(":img/settings.png");
	Val_btn->setIcon(icon);

	//connect(action_cbox, &QComboBox::currentTextChanged, this, &Act_CD::Check_combobox);
	connect(Val_btn, &QPushButton::clicked, this, &Act_CD::Check_action_ed);
}

//message_cl Split_Edit(QString Spl_ed)
//{
//	short int adr = 9;
//	short int subadr = 0;
//	QVector <unsigned short> CD;
//	message_cl tmp_mess(adr,subadr,CD);
//	return tmp_mess;
//
//}


void Act_CD::Check_combobox()
{
	int tmp_int = action_cbox->currentIndex();
	bool tmp_start;
	if (tmp_int = 1)
	{
		tmp_start = true;
	}
	else tmp_start = false;
	contr_data->start = tmp_start;
}

void Act_CD::Check_action_ed()
{
	Control_Dialog sh;
	if (action_ed->text() != "")
	{
		QString tmp_text_from_ed = action_ed->text();
		QStringList list_one = tmp_text_from_ed.split(" ");
		QStringList list_two = list_one[0].split("/");
		QVector <unsigned short> tmp_CD;
		QStringList list_three = list_one[2].split(",");
		//int i = 0;
		//while (list_three[i] != NULL)
		for (int i = 0; i < list_three.size(); i++)
		{
			bool flag;
			unsigned short tmp_short = list_three[i].toUShort(&flag, 16);
			tmp_CD.push_back(tmp_short);
			//i++;
		}
		int tmp_adr = list_two[0].toInt();
		int tmp_subadr = list_two[1].toInt();
		sh.message_m.message_set_data(tmp_adr,tmp_subadr,tmp_CD);
		//sh.message_m = contr_data->message_m;
		sh.renew();
		//sh.set_data(ard,subadr,CD);
		//sh.set_data(contr_data->message_m);
		//sh.Adress_ed->setText(QString::number(contr_data->message_m.adress));
		//sh.Subadress_ed->setText(QString::number(contr_data->message_m.subadress));
		//sh.CD_count_ed->setText(QString::number(contr_data->message_m.CD.count()));
		//sh.CD_ed->setPlainText(contr_data->message_m.form_string_sd);
	}
	else
		contr_data = new Contr_cl;
	if (sh.exec() == QDialog::Accepted)
	{
		contr_data->message_m = sh.message_m;
		action_ed->setText(contr_data->message_m.form_string_all());
		//sh.message_m.form_string_sd();
		//QString tmp_str = sh.message_m.form_string_all();
		//action_ed->text() = sh.message_m.form_string_all();
		//contr_data->message_m = sh.get_message();
		//contr_data->message_m.adress = sh.Adress_ed->text().toInt();
		//contr_data->message_m.subadress = sh.Subadress_ed->text();
		//QString CD_R;
		//QRegExp reg("[\\s]");
		//QString CD = sh.CD_ed->toPlainText();
		//CD.replace(reg, ",");
		//CD_R = sh.CD_ed->toPlainText();
		//int tmp_int = sh.CD_count_ed->text().toInt();
		//QVector <unsigned short> tmp_vec;
		//QStringList Stlist = CD_R.split(QRegExp("\\s+"));
		//for (int i = 0; i < tmp_int; i++)
		//{
		//    unsigned short tmp_short;
		//	bool flag;
		//	tmp_short = Stlist.value(i).toUShort(&flag, 16);
		//	tmp_vec.push_back(tmp_short);
		//}
		//contr_data->message_m.CD = tmp_vec;
		//action_ed->setText(contr_data->message_m.form_string_all());
	}
}