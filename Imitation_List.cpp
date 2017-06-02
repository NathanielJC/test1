#include "Imitation_List.h"

Imitation_List::Imitation_List(QWidget*parent) : QDialog(parent)
{
	one_row = new QLabel(this);
	two_row = new QLabel(this);
	main_lay = new QVBoxLayout(this);
	QPushButton* Cancel = new QPushButton;
	QPushButton* Accept = new QPushButton;
	QHBoxLayout* up_lay = new QHBoxLayout(this);
	QVBoxLayout* mid_l = new QVBoxLayout(this);
	QHBoxLayout* down_l = new QHBoxLayout(this);
	QIcon icon;
	this->setMinimumHeight(450);
	this->setMaximumHeight(450);
	this->setMinimumWidth(500);
	this->setMaximumWidth(500);

	up_lay->addWidget(one_row, 1, Qt::AlignLeft | Qt::AlignTop);
	up_lay->addWidget(two_row, 1, Qt::AlignHCenter | Qt::AlignTop);

	main_lay->addLayout(up_lay);
	main_lay->addLayout(mid_l);

	//Act_Cd_save = new QVector <Act_CD*>;
	//QVector <Act_CD> Act_CD_vec;

	for (int i = 0; i < 9; i++)
	{
		Act_CD* tmp_wdg = new Act_CD(this);// Хранить векторами
		Act_CD_vec.push_back(tmp_wdg);
		//Act_Cd_save->push_back(tmp_wdg);
		mid_l->addWidget(tmp_wdg);
		//bool tmp_start = false;
		//tmp_wdg->contr_data();
		//message_cl tmp_mess = tmp_wdg->message_h;
		//Contr_cl_h = Contr_cl(i, tmp_start, tmp_mess);
		//Contr_tmp.push_back(Contr_cl_h);
		//Act_arr.push_back(tmp_wdg);
	}
	mid_l->addLayout(down_l);
	down_l->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	down_l->addWidget(Cancel);
	down_l->addWidget(Accept);

	one_row->setText("А/ПА/ЧСД-СД");
	two_row->setText("Действие");
	icon.addFile(":img/ok.png");
	Accept->setIcon(icon);
	icon.addFile(":img/cancel.png");
	Cancel->setIcon(icon);

	connect(Accept, &QPushButton::clicked, this, &Imitation_List::save_data);
	connect(Cancel, &QPushButton::clicked, this, &QDialog::reject);
	connect(Accept, &QPushButton::clicked, this, &QDialog::accept);
}

void Imitation_List::set_imit_list(QVector <Contr_cl*> Contrl_tmp)
{
	Contr_cl_h = Contrl_tmp;
	for (int i = 0; i < Contr_cl_h.size(); i++)
	{
		if (Contr_cl_h.size() != 0)
		{
			if (Contr_cl_h.at(i)->message_m.adress != NULL)
			{
				Act_CD_vec[i]->action_ed->setText(Contr_cl_h.at(i)->message_m.form_string_all());
				if (Contr_cl_h.at(i)->start = true)
					Act_CD_vec[i]->action_cbox->setCurrentIndex(0);
				else Act_CD_vec[i]->action_cbox->setCurrentIndex(1);
				Act_CD_vec[i]->contr_data = Contr_cl_h.at(i);
			}
		}
	}
}
	void Imitation_List::save_data()
	{
		Contr_cl_h.clear();
		for (int i = 0; i < Act_CD_vec.size(); i++)
		{
			if (Act_CD_vec[i]->action_ed->text() != "")
			Contr_cl_h.push_back(Act_CD_vec[i]->contr_data);
			//else
			//Contr_cl_h[i] = Act_CD_vec[i]->contr_data;
		}
		//for (int i = 0; i < 9; i++)
		//{
		//	if (Act_CD_vec[i]->action_ed->text() != "")
		//	Contr_cl_h.push_back(Act_CD_vec[i]->contr_data);
		//}
	}
