#ifndef IMIT_AB_H
#define IMIT_AB_H
#include <qstring.h>
#include <qvector.h>
#include "State.h"

class Imit_ab_cl
{
	QString Name;
	short int id;
	bool enable;
	short int adress;
	short int subadress;
	short int count_CD;
	QVector <StateData> State_m;
public:
	Imit_ab_cl()
	{
		Name = "";
		id = 0;
		enable = 0;
		adress = 0;
		subadress = 0;
		count_CD = 0;
	}
	Imit_ab_cl(QString Name_, int id_, bool enable_, short int adress_, short int subadress_, short int count_CD_, QVector<StateData> State_m_)
	{
		Name = Name_;
		id = id_;
		enable = enable_;
		adress = adress_;
		subadress = subadress_;
		count_CD = count_CD_;
		State_m = State_m_;
	}
};

#endif // IMITAB_H