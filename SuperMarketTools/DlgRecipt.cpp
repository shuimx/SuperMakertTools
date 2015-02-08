// DlgRecipt.cpp : 实现文件
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgRecipt.h"
#include "afxdialogex.h"


// CDlgRecipt 对话框

IMPLEMENT_DYNAMIC(CDlgRecipt, CDialogEx)

CDlgRecipt::CDlgRecipt(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgRecipt::IDD, pParent)
{

}

CDlgRecipt::~CDlgRecipt()
{
}

void CDlgRecipt::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRecipt, CDialogEx)
END_MESSAGE_MAP()


// CDlgRecipt 消息处理程序
