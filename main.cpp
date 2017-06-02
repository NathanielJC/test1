#include <qtextcodec.h>
#include <qapplication.h>
#include "gui.h"


int main(int argc, char ** argv)
{
	QApplication a(argc, argv);
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	
	FirstClass w;
	w.showMaximized();
	return a.exec();
}
