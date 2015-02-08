// DlgAddCustom.cpp : 实现文件
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgAddCustom.h"
#include "afxdialogex.h"


// CDlgAddCustom 对话框

IMPLEMENT_DYNAMIC(CDlgAddCustom, CDialogEx)

CDlgAddCustom::CDlgAddCustom(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgAddCustom::IDD, pParent)
{

}

CDlgAddCustom::~CDlgAddCustom()
{
}

void CDlgAddCustom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgAddCustom, CDialogEx)
END_MESSAGE_MAP()


// CDlgAddCustom 消息处理程序
