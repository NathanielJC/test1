#ifndef BV_H
#define BV_H
#include <qstring.h>
class BV_cl
{
	//QTime ott();
	//QTime doo();
public:
	QString ot_t;
	QString do_o;
	BV_cl()//QTime
	{
		ot_t = "";
		do_o = "";
	}
	BV_cl(QString ot_, QString do_)
	{
		ot_t = ot_;
		do_o = do_;
	}
	//BV_cl set_BV_s(QString ot_, QString do_)
	//{
	//	ot_t = ot_;
	//	do_o = do_;
	//	BV_cl tmp_Bv_S(ot_t,do_o);
	//	return tmp_Bv_S;
	//}
};


#endif // BV_H