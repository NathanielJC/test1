#ifndef BV_H_OT_DO_CLASS
#define BV_H_OT_DO_CLASS
#include <qstring.h>
#include <qlabel.h>
#include <qlineedit.h>
class BV_ot_do_class : public QWidget
{
	Q_OBJECT
public:
	BV_ot_do_class(QWidget* parent = 0);
public:
	QLineEdit* ot_ed;
	QLineEdit* do_ed;

	QLabel* ot_lab;
	QLabel* do_lab;
};
#endif // BV_H_OT_DO_CLASS