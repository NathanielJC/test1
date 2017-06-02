#include "ExSetDialog.h"
#include "windows.h"
#include "Imitation_List.h"
#include "Dialog_val.h"
#include "BV.h"
#include "Action_CD.h"

ExchangeSetDialog::ExchangeSetDialog(QWidget* parent) : QDialog(parent)
{
	main_lay = new QVBoxLayout(this);
	mid_lay = new QHBoxLayout(this);
	up_lay = new QVBoxLayout(this);
	QGridLayout* mid_grid = new QGridLayout(this);
    QGroupBox* mid_box = new QGroupBox(this);
	QVBoxLayout* mid_v_lay = new QVBoxLayout(this);
	QGroupBox* down_box = new QGroupBox(this);
	QGridLayout* down_grid = new QGridLayout(this);
	QHBoxLayout* down_v_lay = new QHBoxLayout(this);
	down_h_lay = new QVBoxLayout(this);
	QHBoxLayout* down_btn_lay = new QHBoxLayout(this);
	data_word_lab = new QLabel(this);
	data_word_ed = new QTextEdit(this);
	BV_lab = new QLabel(this);
	join_BV_chb = new QCheckBox(this);
	stop_btn = new QPushButton(this);
	accept_btn = new QPushButton(this);
	con_ex_lab = new QLabel(this);
	back_btn = new QPushButton(this);
	QIcon icon;

	this->setMaximumHeight(455);
	this->setMinimumHeight(455);
	this->setMinimumWidth(400);
	this->setMaximumWidth(400);
	data_word_ed->setMaximumHeight(80);
	data_word_ed->setMaximumWidth(295);
	data_word_ed->setMinimumWidth(295);
	stop_btn->setContentsMargins(0, 0, 0, 0);
	accept_btn->setContentsMargins(0, 0, 0, 0);
	back_btn->setContentsMargins(0, 0, 0, 0);

	up_lay->addWidget(data_word_lab,0,Qt::AlignHCenter|Qt::AlignTop);
	up_lay->addWidget(data_word_ed, 0, Qt::AlignHCenter|Qt::AlignTop);
	main_lay->addLayout(up_lay);
	mid_lay->addWidget(BV_lab);
	mid_lay->addWidget(join_BV_chb, 1, Qt::AlignRight | Qt::AlignTop);
	BV_s_wid = new QVector <BV_ot_do_class*>;
	//BV_s = new QVector <BV_cl*>;
	for (int i = 1; i <= 4; i++)
	{
		BV_ot_do_class* tmp_cl_wdg = new BV_ot_do_class(this);
		BV_s_wid->push_back(tmp_cl_wdg);
		switch (i)
		{
			case 1 : mid_grid->addWidget(tmp_cl_wdg, 1, 1);
			case 2 : mid_grid->addWidget(tmp_cl_wdg, 1, 2);
			case 3 : mid_grid->addWidget(tmp_cl_wdg, 3, 1);
			case 4 : mid_grid->addWidget(tmp_cl_wdg, 3, 2);
		}
	}
	mid_v_lay->addLayout(mid_lay);
	mid_v_lay->addLayout(mid_grid);
	mid_box->setLayout(mid_v_lay);
	main_lay->addWidget(mid_box);
	down_v_lay->addWidget(con_ex_lab, 1, Qt::AlignLeft);
	down_v_lay->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	down_v_lay->addWidget(back_btn);
	down_h_lay->addLayout(down_v_lay);

	//Act_rep = new QVector <Act_CD*>;

	for (int i = 0; i < 2; i++)
	{
		Act_CD* tmp_wdg = new Act_CD(this);// тот же вектор что и раньше
		Act_rep.push_back(tmp_wdg);
		down_h_lay->addWidget(tmp_wdg);
		if (contr_sv.size() != 0)
		{
			if (contr_sv.at(i)->message_m.adress != NULL)
			{
				tmp_wdg->action_ed->setText(contr_sv.at(i)->message_m.form_string_all());
				if (contr_sv.at(i)->start = true)
					tmp_wdg->action_cbox->setCurrentIndex(0);
				else tmp_wdg->action_cbox->setCurrentIndex(1);
			}
		}
		//save_vec.push_back(tmp_wdg);
	}
	down_box->setLayout(down_h_lay);
	main_lay->addWidget(down_box);
	main_lay->addLayout(down_btn_lay);
	down_btn_lay->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	down_btn_lay->addWidget(stop_btn);
	down_btn_lay->addWidget(accept_btn);

	data_word_lab->setText("Слова данных");
	BV_lab->setText("БВ");
	join_BV_chb->setText("Привязка к БВ");

	icon.addFile(":img/B_p.png");
	back_btn->setIcon(icon);
	icon.addFile(":img/ok.png");
	accept_btn->setIcon(icon);
	icon.addFile(":img/cancel.png");
	stop_btn->setIcon(icon);

	QFont NewFont("Courier New", 8);
	data_word_ed->setFont(NewFont);
	con_ex_lab->setText("Контроль обменов");

	data_word_ed->setMinimumHeight(20);

	connect(stop_btn, &QPushButton::clicked, this, &QDialog::reject);
	connect(accept_btn, &QPushButton::clicked, this, &QDialog::accept);
	connect(accept_btn, &QPushButton::clicked, this, &ExchangeSetDialog::Save_State);
	connect(data_word_ed, &QTextEdit::textChanged, this, &ExchangeSetDialog::TextValidator);
	connect(back_btn, &QPushButton::clicked, this, &ExchangeSetDialog::Save_Act);
	connect(back_btn, &QPushButton::clicked, this, &ExchangeSetDialog::Imitation_List_add);
}
void ExchangeSetDialog::TextValidator()
{
	ActivateKeyboardLayout((HKL)MAKELANGID(LANG_ENGLISH, SUBLANG_DEFAULT), KLF_SETFORPROCESS);//Автоматически пишет на латинице
	QString new_text = data_word_ed->toPlainText().toUpper();
	if (new_text.size() > 159)
		new_text.remove(159, new_text.size() - 159);
	new_text.replace(QRegExp("[^A-F0-9]"), "");
	QStringList em_sp;
	for (int i = 0; i < new_text.length(); i += 4)
		em_sp << new_text.mid(i, 4);
	QStringList tab_sp;
	data_word_ed->blockSignals(true);
	data_word_ed->setText(em_sp.join(" "));
	if (new_text.size() < 159)
	data_word_ed->moveCursor(QTextCursor::EndOfBlock);
	data_word_ed->blockSignals(false);
	
};

void ExchangeSetDialog::Save_State()
{
	for (int i = 0; i < 4; i++)
	{
		//if (BV_s.size() != 0)
		//{
		if ((BV_s_wid->at(i)->ot_ed->text() != "") & (BV_s_wid->at(i)->do_ed->text() != ""))
			{
				BV_cl* tmp_bv = new BV_cl;
				tmp_bv->do_o = BV_s_wid->at(i)->do_ed->text();
				tmp_bv->ot_t = BV_s_wid->at(i)->ot_ed->text();
				BV_s.push_back(tmp_bv);
				//BV_s.at(i)->ot_t = BV_s_wid->at(i)->ot_ed->text();
				//BV_s.at(i)->do_o = BV_s_wid->at(i)->do_ed->text();
			}
		//}
		//else
		//{
		//	BV_cl* tmp_bv = new BV_cl;
		//	tmp_bv->do_o = BV_s_wid->at(i)->do_ed->text();
		//	tmp_bv->ot_t = BV_s_wid->at(i)->ot_ed->text();
		//	BV_s.push_back(tmp_bv);
		//}
	}
		//State_s.BV_M = BV_s;
		//State_s.bv_enable = join_BV_chb->isTristate();
		QVector <unsigned short> CD_complete;
		QStringList tmp_str;
		tmp_str = data_word_ed->toPlainText().split(" ");
		for (int i = 0; i < tmp_str.count(); i++)
		{
			unsigned short tmp_short;
			bool flag;
			tmp_short = tmp_str[i].toUShort(&flag, 16);
			CD_complete.push_back(tmp_short);
		}
		//State_s.CD = CD_complete;
		State_s->State_ident(tmp_Name, join_BV_chb->isTristate(),CD_complete,BV_s,contr_sv);
}
void ExchangeSetDialog::Save_Act()
{
	if (contr_sv.size() == 0)
	{
		for (int i = 0; i < 2; i++)
		{
			if (Act_rep[i]->action_ed->text() != "")
				contr_sv.push_back(Act_rep[i]->contr_data);
		}
	}
	else
	{
		if (contr_sv.size() == 1)
		{
			contr_sv[0] = Act_rep[0]->contr_data;
		}
		if (contr_sv.size() > 1)
		{
			for (int i = 0; i < 2; i++)
			{
				contr_sv[i] = Act_rep[i]->contr_data;
			}
		}
	}
}
void ExchangeSetDialog::Imitation_List_add()
{
	Imitation_List sh;
	sh.set_imit_list(contr_sv);
		//if (contr_sv.size() = 0) // Если до этого contr_sv не был заполнен.
		//	{
		//		contr_sv.push_back(Act_rep->at(0)->contr_data);
		//		contr_sv.push_back(Act_rep->at(1)->contr_data);
		//	}
		//	else //Если в contr_sv уже были забиты значения.
		//	{
		//		contr_sv[0] = Act_rep->at(0)->contr_data;
		//		contr_sv[1] = Act_rep->at(1)->contr_data;
		//	} 
	//	if (contr_sv.size() == 0)
	//	{
	//		contr_sv.push_back(Act_rep->at(i)->contr_data);
	//	}
	//	else
	//	if (contr_sv[i])
	//		contr_sv[i] = Act_rep->at(i)->contr_data;
	//}
	//if (contr_sv.at(0)->message_m.adress = NULL) // Если до этого contr_sv не был заполнен.
	//{
	//	contr_sv.push_back(Act_rep->at(0)->contr_data);
	//	contr_sv.push_back(Act_rep->at(1)->contr_data);
	//}
	//else //Если в contr_sv уже были забиты значения.
	//{
	//	contr_sv[0] = Act_rep->at(0)->contr_data;
	//	contr_sv[1] = Act_rep->at(1)->contr_data;
	//}
	//sh.Contr_cl_h = contr_sv;
	//for (int i = 0; i < contr_sv.size(); i++)
	//{
	//	sh.Act_CD_vec[i]->contr_data = contr_sv[i];
	//}
	//if ((Act_rep->at(0)->action_ed->text() != "")|(Act_rep->at(1)->action_ed->text() != ""))
	//{
	//	for (int i = 0; i <2; i++)
	//	{
	//		sh.Act_CD_vec[i]->contr_data = Act_rep->at(i)->contr_data;
	//		sh.Act_Cd_save->at(i)->action_ed->setText(Act_rep->at(i)->action_ed->text());
	//		//sh.Act_CD_vec[i]->
	//	}
	//	for (int i = 2; i < 9; i++)
	//	{
	//		sh.Act_CD_vec[i]->contr_data = contr_sv[i];
	//	}
	//}
	//sh.Contr_cl_h = contr_sv;
	//for (int i = 0; i < 2; i++)
	//{
	//	sh.Act_arr.replace(i, ExchangeSetDialog::save_vec.value(i));
	//}
	if (sh.exec() == QDialog::Accepted)
	{
		contr_sv = sh.Contr_cl_h;
		for (int i = 0; i < 2; i++)
		{
			Act_rep[i]->contr_data = contr_sv[i];
			Act_rep[i]->action_ed->setText(Act_rep[i]->contr_data->message_m.form_string_all());
		}
		//if (sh.Contr_cl_h[0] != NULL)
		//{
			//contr_sv.clear();
			//Act_rep.clear();
			//for (int i = 0; (i <= Act_rep->size() - 1) & (i < 2); i++)
		//	{
				//contr_sv[i] = sh.Act_CD_vec[i]->contr_data;
			 //   contr_sv = sh.Contr_cl_h;
				//Act_rep->at(i)->contr_data = sh.Contr_cl_h[i];
				//Act_rep->at(i)->action_ed->setText(contr_sv[i]->message_m.form_string_all());
				//contr_sv[i] = sh.Contr_cl_h[i];
				//Act_rep[i] = sh.Act_CD_vec[i];
				//down_h_lay->;
			//}

		}
	}