// DlgAddCustom.cpp : 实现文件
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgAddCustom.h"
#include "afxdialogex.h"
#include "Util.h"


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
	ON_BN_CLICKED(IDOK, &CDlgAddCustom::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgAddCustom 消息处理程序


void CDlgAddCustom::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cName;
	CString cPhone;
	CString cCount;
	CString cNote;
	int i,len;
	CString cmd;


	CEdit* pEditCtr; 
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT1); 
	pEditCtr-> GetWindowText(cName);
 
	// 手机号检查
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT2); 
	pEditCtr-> GetWindowText(cPhone);
	if(cPhone.GetLength() != 11){
		AfxMessageBox(_T("手机号输入错误。手机号要为11位数字。"),MB_OKCANCEL);
		return;
	}
	for(i = 0; i < 11; i++){
		if((cPhone.GetAt(i) > '9')|| (cPhone.GetAt(i) < '0')){
			AfxMessageBox(_T("手机号输入错误。手机号要为11位数字。"),MB_OKCANCEL);
			return;
		}
	}
 
	// 输入消费金额检查
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT4); 
	pEditCtr-> GetWindowText(cCount);
	len = cCount.GetLength();
	for(i = 0; i < len; i++){
		if((cCount.GetAt(i) > '9')|| (cCount.GetAt(i) < '0') && (cCount.GetAt(i)!='.')){
			AfxMessageBox(_T("消费金额输入错误。格式为 12 或是 1.5。"),MB_OKCANCEL);
			return;
		}
	}

	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT3); 
	pEditCtr-> GetWindowText(cNote);

	cmd.Format("insert into customers(name,sex,phone,address,note)" 
		      "values('%s','','%s','','%s')",cName, cPhone, cNote);
	CSMTDataBase db;
	if(db.Query(cmd)){
		AfxMessageBox(_T("成功增加一位会员"),MB_OK);
	}else{
		AfxMessageBox(_T("操作失败"),MB_OK);
	}

	if(cCount.GetLength()){
		cmd.Format("SELECT LAST_INSERT_ID()");
		CString cID;
		char tempID[10] = {'\0'};
		db.QueryAndFetch(cmd, tempID);
		cID.Format("%s", tempID);

		CUtil util;
		CString cTime;
		cTime = util.GetCurrentSysTime();
		cmd.Format("insert into records(user_id,record_time,amount)" 
				  "values('%s','%s','%s') ",cID, cTime, cCount);
		if(db.Query(cmd)){
			AfxMessageBox(_T("成功记录此次消费"),MB_OK);
		}else{
			AfxMessageBox(_T("操作失败"),MB_OK);
		}
	}
	CDialogEx::OnOK();
}
