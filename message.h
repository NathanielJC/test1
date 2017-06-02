#ifndef MESSAGE_H
#define MESSAGE_H
#include <qstring.h>
#include <qvector.h>

class message_cl
{
public:
	short int adress;
	short int subadress;
	QVector <unsigned short> CD;// convert from QString
	short get_adress(){ return adress; }
	message_cl()
	{
		adress = 0;
		subadress = 0;

	}
	message_cl(short int ad, short int sub,  QVector <unsigned short> CD_W)
	{
		adress = ad;
		subadress = sub;
		CD = CD_W;
	}
	message_cl message_set_data(short int ad, short int sub, QVector <unsigned short> CD_W)
	{
		adress = ad;
		subadress = sub;
		CD = CD_W;
		message_cl message_tmp(ad, sub, CD_W);
		return message_tmp;
	}

	QString form_string_sd()
	{
		QString tmp_str;
		for (int i = 0; i < CD.count(); ++i)
		{
			tmp_str += QString("%1 ").arg(CD[i], 4, 16, QChar('0')).toUpper();
		}
		tmp_str.chop(1);
		return tmp_str;
	}
	QString form_string_all()
	{
		QString CD_str = form_string_sd();
		return QString("%1/%2/%3 - %4").arg(adress).arg(subadress).arg(CD.count()).arg(CD_str.replace(" ", ","));
	}
};


#endif // MESSAGE_H