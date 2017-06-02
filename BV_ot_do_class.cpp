#include "BV_ot_do_class.h"
#include <qgridlayout.h>
BV_ot_do_class::BV_ot_do_class(QWidget*parent) : QWidget(parent)
{
	QGridLayout* gr_lay = new QGridLayout(this);

	ot_lab = new QLabel(this);
	ot_ed = new QLineEdit(this);
	do_lab = new QLabel(this);
	do_ed = new QLineEdit(this);

	gr_lay->addWidget(ot_lab,1,1,Qt::AlignHCenter);
	gr_lay->addWidget(ot_ed, 2, 1);
	//gr_lay->addItem(new QSpacerItem(30, 30, QSizePolicy::Expanding, QSizePolicy::Expanding), 1, 2);
	gr_lay->addWidget(do_lab, 1, 2, Qt::AlignHCenter);
	gr_lay->addWidget(do_ed, 2,2);

	ot_lab->setText("от");
	do_lab->setText("до");

	ot_ed->setInputMask("99:99:99");
	do_ed->setInputMask("99:99:99");

	ot_ed->setMaximumWidth(80);
	do_ed->setMaximumWidth(80);
};