
// SuperMarketTools.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSuperMarketToolsApp:
// �йش����ʵ�֣������ SuperMarketTools.cpp
//

class CSuperMarketToolsApp : public CWinApp
{
public:
	CSuperMarketToolsApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSuperMarketToolsApp theApp;