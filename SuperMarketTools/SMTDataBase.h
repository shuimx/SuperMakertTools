#include "mysql.h"

#pragma once

// CSMTDataBase ����Ŀ��

class CSMTDataBase : public CDatabase
{
public:
	CSMTDataBase();
	virtual ~CSMTDataBase();

	MYSQL mydata;
	bool Query(const char* cmd);
	bool QueryAndFetch(const char* cmd, char *res);
};


