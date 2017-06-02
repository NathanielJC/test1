#include "AbWidg.h"
#include <qmessagebox.h>
#include <qboxlayout.h>
#include <qicon.h>


AbWidget::AbWidget(QWidget* parent) : QWidget(parent)
{
	obj_num++;
	QHBoxLayout* main_lay = new QHBoxLayout(this);
	Check_box = new QCheckBox(this);
	Name_line = new QLineEdit(this);
	Settings_btn = new QPushButton(this);
	Add_btn = new QPushButton(this);
	Delete_btn = new QPushButton(this);
	obj_num_l = new QLabel(this);
	QIcon icon;

	Name_line->setMinimumWidth(150);
	Name_line->setMaximumWidth(370);

	main_lay->addWidget(obj_num_l);
	obj_num_l->setVisible(false);
	main_lay->addWidget(Check_box);
	main_lay->addWidget(Name_line);
	main_lay->addWidget(Settings_btn);
	main_lay->addWidget(Add_btn);
	main_lay->addWidget(Delete_btn);
	Name_line->setReadOnly(true);

	icon.addFile(":img/add.png");
	Add_btn->setIcon(icon);
	icon.addFile(":img/delete.png");
	Delete_btn->setIcon(icon);
	icon.addFile(":img/settings.png");
	Settings_btn->setIcon(icon);

	connect(Add_btn, &QPushButton::clicked, this, &AbWidget::add_new_abnt);
	connect(Settings_btn, &QPushButton::clicked, this, &AbWidget::settings_btn_click);
	connect(Delete_btn, &QPushButton::clicked, this, &AbWidget::delete_abnt);
};

void AbWidget::settings_btn_click()
{
	SettingsDialog sh;
	if (Name_line->text() != NULL)
		sh.Name_Edit->setText(Name_line->text());
	if (sh.exec() == QDialog::Accepted)
	{
		Name_line->setText(sh.Name_Edit->text());
	}
}

void AbWidget::check_box_click(bool box_en)
{

}

void AbWidget::set_obj_num(int _obj_num)
{
	obj_num_l->setText(QString::number(_obj_num));
	obj_num = _obj_num;
}