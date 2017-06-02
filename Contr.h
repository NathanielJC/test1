#ifndef CONTR_H
#define CONTR_H
#include <qstring.h>
#include <qvector.h>
#include "message.h"

class Contr_cl
{
	//short int id;

public:
	bool start;
	message_cl message_m;
	Contr_cl()
	{
		//id = 0;
		start = 1;
	}
	Contr_cl(/*int id_,*/ bool start_, message_cl message_m_)
	{
		//id = id_;
		start = start_;
		message_m = message_m_;
	}
	Contr_cl Contrl_set_data(bool start_, message_cl message_m_)
	{
		start = start_;
		message_m = message_m_;
		Contr_cl tmp_contrl(start_, message_m_);
		return tmp_contrl;
	}
};


#endif // CONTR_H