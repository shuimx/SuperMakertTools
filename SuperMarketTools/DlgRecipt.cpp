// DlgRecipt.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgRecipt.h"
#include "afxdialogex.h"

#include "Util.h"
#include "SMTDataBase.h"


// CDlgRecipt �Ի���

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


// CDlgRecipt ��Ϣ�������


void CDlgRecipt::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cPhone;
	CString cName;
	CString cPreCountSum;
	CString cCount;
	CString cNote;

	CDialogEx::OnOK();
}
