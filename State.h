#ifndef STATE_H
#define STATE_H
#include <qstring.h>
#include <qvector.h>
#include "BV.h"
#include "Contr.h"

class StateData
{
public:
	QString Name;
	bool bv_enable;
	QVector <unsigned short> CD;// convert from Qstring
	QVector <BV_cl*> BV_M;
	QVector <Contr_cl*> Contr_m;
	StateData()
	{
		Name = "";
		bv_enable = 0;
	}
	StateData(QString Name_, bool bv_enable_, QVector<unsigned short> CD_, QVector<BV_cl*> BV_M_, QVector<Contr_cl*> Contr_m_)
	{
		Name = Name_;
		bv_enable = bv_enable_;
		CD = CD_;
		BV_M = BV_M_;
		Contr_m = Contr_m_;
	}
	StateData State_ident(QString Name_, bool bv_enable_, QVector<unsigned short> CD_, QVector<BV_cl*> BV_M_, QVector<Contr_cl*> Contr_m_)
	{
		Name = Name_;
		bv_enable = bv_enable_;
		CD = CD_;
		BV_M = BV_M_;
		Contr_m = Contr_m_;
		StateData State_t(Name, bv_enable, CD, BV_M, Contr_m);
		return State_t;
	}
};


#endif // STATE_H