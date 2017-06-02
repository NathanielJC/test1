#include "AbSetDialog.h"


SettingsDialog::SettingsDialog(QWidget*parent) : QDialog(parent)
{
	sec_lay = new QVBoxLayout(this);
	sett_lay = new QVBoxLayout(this);
	QGroupBox* gr_box = new QGroupBox(this);
	Name_Label = new QLabel(this);
	Name_Edit = new QLineEdit(this);
	QGridLayout* grid_lay = new QGridLayout(this);
	QHBoxLayout* tmp_lay = new QHBoxLayout(this);
	Adress_Edit = new QLineEdit(this);
	Adress_label = new QLabel(this);
	Unadress_label = new QLabel(this);
	Unadress_Edit = new QLineEdit(this);
	SD_label = new QLabel(this);
	SD_Edit = new QLineEdit(this);
	Control_Label = new QLabel(this);
	Stop_btn = new QPushButton(this);
	Accept_btn = new QPushButton(this);
	d_lay = new QGridLayout(this);
	Magistral = new QLabel(this);
	Magistral_edit = new QLineEdit(this);
	QVBoxLayout* l_lay = new QVBoxLayout(this);
	QIcon icon;

	this->setMinimumWidth(800);
	this->setMinimumHeight(460);
	this->setMaximumWidth(800);
	this->setMaximumHeight(460);
	Name_Edit->setMinimumWidth(250);
	Name_Edit->setMaxLength(40);
	Adress_Edit->setMaximumWidth(80);
	Adress_Edit->setMaxLength(2);
	Magistral_edit->setMaximumWidth(80);
	Magistral_edit->setMaxLength(1);
	Unadress_Edit->setMaximumWidth(80);
	Unadress_Edit->setMaxLength(2);
	SD_Edit->setMaximumWidth(80);
	SD_Edit->setMaxLength(2);
	Stop_btn->setContentsMargins(0, 0, 0, 0);
	Accept_btn->setContentsMargins(0, 0, 0, 0);

	sett_lay->addWidget(Name_Label, 0, Qt::AlignHCenter|Qt::AlignTop);
	sett_lay->addWidget(Name_Edit, 0, Qt::AlignHCenter|Qt::AlignTop);
	sett_lay->addLayout(grid_lay);
	grid_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum),1,0);
	grid_lay->addWidget(Magistral, 1, 1);
	grid_lay->addWidget(Magistral_edit, 2, 1);
	grid_lay->addWidget(Adress_label,1,2);
	grid_lay->addWidget(Adress_Edit,2,2);
	grid_lay->addWidget(Unadress_label,1,3);
	grid_lay->addWidget(Unadress_Edit,2,3);
	grid_lay->addWidget(SD_label,1,4);
	grid_lay->addWidget(SD_Edit,2,4);
	grid_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum), 1, 5);
	sec_lay->addWidget(gr_box);
	gr_box->setLayout(sett_lay);
	l_lay->addWidget(Control_Label, 0, Qt::AlignCenter | Qt::AlignTop);
	sec_lay->addLayout(l_lay);

	add_new_widg();

	sec_lay->addLayout(d_lay);
	tmp_lay->addSpacerItem(new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum));
	tmp_lay->addWidget(Stop_btn);
	tmp_lay->addWidget(Accept_btn);
	sec_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding));
	sec_lay->addLayout(tmp_lay);

	delete_widg();

	d_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), 6, 0);

	icon.addFile(":img/ok.png");
	Accept_btn->setIcon(icon);
	icon.addFile(":img/cancel.png");
	Stop_btn->setIcon(icon);
	Name_Label->setText("Имя имитатора абонента");
	Adress_label->setText("Адрес");
	Unadress_label->setText("Подадрес");
	SD_label->setText("Количество СД");
	Magistral->setText("Магистраль");
	Control_Label->setText("Управление абонентами");
	this->setWindowTitle("Настройка имитатора абонента");
	connect(Stop_btn,&QPushButton::clicked,this,&QDialog::reject);
	connect(Accept_btn, &QPushButton::clicked, this, &QDialog::accept);
};
void SettingsDialog::add_new_widg()
{
	int tmp_count = WMap.count();
	if (tmp_count < 12)
	{
		StateWidget *tmp_widg = new StateWidget(this);
		tmp_widg->set_obj_num(count);
		tmp_widg->setFixedWidth(400);
		d_lay->addWidget(tmp_widg, tmp_count % 6, tmp_count / 6);
		connect(tmp_widg, &StateWidget::add_new_state, this, &SettingsDialog::add_new_widg);
		connect(tmp_widg, &StateWidget::delete_state, this, &SettingsDialog::delete_widg);
		WMap.insert(count, tmp_widg);
		count++;
	}
}
void SettingsDialog::delete_widg()
{
	if (sender() != NULL)
	{
		for (QMap<int, QWidget*>::iterator itr = WMap.begin(); itr != WMap.end(); ++itr)
		{
			d_lay->removeWidget(itr.value());
		}
		int tmp_num = static_cast<StateWidget*>(sender())->get_obj_num();
		WMap.remove(tmp_num);
		static_cast<StateWidget*>(sender())->deleteLater();
		int i = 0;
		for (QMap<int, QWidget*>::iterator itr = WMap.begin(); itr != WMap.end(); ++itr)
		{
			d_lay->addWidget(itr.value(), i % 6, i / 6);
			i++;
		}
	}
}

StateWidget::StateWidget(QWidget*parent) : QWidget(parent)
{
	obj_num++;
	QHBoxLayout* sec_lay = new QHBoxLayout(this);
	obj_num_l = new QLabel(this);
	Name_settings_line = new QLineEdit(this);
	Delete_settings_btn = new QPushButton(this);
	Settings_settings_btn = new QPushButton(this);
	Add_settings_btn = new QPushButton(this);
	QIcon icon;

	sec_lay->addWidget(obj_num_l);
	obj_num_l->setVisible(false);
	sec_lay->addWidget(Name_settings_line);
	sec_lay->addWidget(Settings_settings_btn);
	sec_lay->addWidget(Add_settings_btn);
	sec_lay->addWidget(Delete_settings_btn);

	icon.addFile(":img/add.png");
	Add_settings_btn->setIcon(icon);
	icon.addFile(":img/delete.png");
	Delete_settings_btn->setIcon(icon);
	icon.addFile(":img/settings.png");
	Settings_settings_btn->setIcon(icon);

	connect(Add_settings_btn, &QPushButton::clicked, this, &StateWidget::add_new_state);
	connect(Delete_settings_btn, &QPushButton::clicked, this, &StateWidget::delete_state);
	connect(Settings_settings_btn, &QPushButton::clicked, this, &StateWidget::settings_btn_click);
}
void StateWidget::settings_btn_click()
{
	ExchangeSetDialog set_dialog;

	//set_dialog.setData(sett_data);  //TODO: Передавать хранимые данные для отобажения их в диалоге настроек (редактирование по сути)
	set_dialog.tmp_Name = Name_settings_line->text();
	if (set_dialog.exec() == QDialog::Accepted)
	{
		state_data.push_back(set_dialog.State_s);

		//sett_data = set_dialog.getData(); //TODO: Получить данные из диалога настроек
	}
}
void StateWidget::set_obj_num(int _obj_num)
{
	obj_num_l->setText(QString::number(_obj_num));
	obj_num = _obj_num;
}