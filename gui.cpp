#include "gui.h"
#include <math.h>

FirstClass::FirstClass(QWidget* parent) : QWidget(parent)
{
	main_lay = new QGridLayout(this);
	main_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), raz, 0);
	main_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), raz, 1);
	main_lay->addItem(new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Expanding), raz, 2);
	main_lay->setSpacing(5);

	add_new_widg();

	this->setWindowTitle("Имитируемые абоненты");
}

void FirstClass::add_new_widg()
{
	int tmp_count = WMap.count();
	if (tmp_count < raz*3)
	{
		AbWidget* tmp_widg = new AbWidget(this);

		tmp_widg->set_obj_num(count);
		tmp_widg->setFixedWidth(550);
		WMap.insert(count, tmp_widg);
		count++;

		main_lay->addWidget(tmp_widg, tmp_count % raz, tmp_count / raz, Qt::AlignLeft | Qt::AlignTop);

		connect(tmp_widg, &AbWidget::add_new_abnt, this, &FirstClass::add_new_widg);
		connect(tmp_widg, &AbWidget::delete_abnt, this, &FirstClass::delete_this_abnt);
	}
}

void FirstClass::delete_this_abnt()
{
	if (sender() != NULL)
	{
		for (QMap<int, QWidget*>::iterator itr = WMap.begin(); itr != WMap.end(); ++itr)
		{
			main_lay->removeWidget(itr.value());
		}
		int tmp_num = static_cast<AbWidget*>(sender())->get_obj_num();
		WMap.remove(tmp_num);
		static_cast<AbWidget*>(sender())->deleteLater();
		int i = 0;
		for (QMap<int, QWidget*>::iterator itr = WMap.begin(); itr != WMap.end(); ++itr)
		{
			main_lay->addWidget(itr.value(), i % raz, i / raz);
			i++;
		}
	}
}