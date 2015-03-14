// DlgRecipt.cpp : 实现文件
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgRecipt.h"
#include "afxdialogex.h"

#include "Util.h"
#include "SMTDataBase.h"


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
	ON_BN_CLICKED(IDOK, &CDlgRecipt::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgRecipt 消息处理程序


void CDlgRecipt::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cPhone;
	CString cName;
	CString cPreCountSum;
	CString cCount;
	CString cNote;

	CDialogEx::OnOK();
}
