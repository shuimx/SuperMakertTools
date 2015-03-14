#include "StdAfx.h"
#include "Util.h"


CUtil::CUtil(void)
{
}


CUtil::~CUtil(void)
{
}

CString CUtil::GetCurrentSysTime(){ 
	CString t;
	CTime curTime = CTime::GetCurrentTime();
	t = curTime.Format("%Y-%m-%d %H:%M:%S");
	return t;
}
