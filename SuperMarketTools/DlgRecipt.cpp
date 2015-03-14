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
	, cUserId(_T(""))
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
	ON_BN_CLICKED(IDC_QUERY, &CDlgRecipt::OnBnClickedQuery)
END_MESSAGE_MAP()


// CDlgRecipt 消息处理程序


void CDlgRecipt::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cCount;
	CEdit* pEditCtr; 
	int len, i;

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

	CSMTDataBase db;
	CString cmd;
	CUtil util;
	CString cTime;

	cTime = util.GetCurrentSysTime();
	cmd.Format("insert into records(user_id,record_time,amount)" 
				"values('%s','%s','%s') ",cUserId, cTime, cCount);
	if(db.Query(cmd)){
		AfxMessageBox(_T("成功记录此次消费"),MB_OK);
	}else{
		AfxMessageBox(_T("操作失败"),MB_OK);
	}

	CDialogEx::OnOK();
}


void CDlgRecipt::OnBnClickedQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cPhone;
	CString cName;
	CString cPreCountSum;
	CString cNote;
	int i;

	CEdit* pEditCtr; 
 
	// 手机号格式检查
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT1); 
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
	// 检查是否是会员
	CSMTDataBase db;
	CString cmd;
	char num[2]={'\0'};

	cmd.Format("select count(*) from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, num);
	if(num[0]=='0'){
		AfxMessageBox(_T("此手机号不是会员，请加入会员。"),MB_OK);
		return;
	}

	// 获取会员名字
	char tempName[64]={'\0'};
	cmd.Format("select name from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, tempName);
	cName.Format("%s", tempName);
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT2); 
	pEditCtr-> SetWindowText(cName);

	// 获取历史消费金额
	char tempID[18]={'\0'};
	char tempCount[4]={'\0'};
	cmd.Format("select id from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, tempID);
	cUserId.Format("%s", tempID);
	cmd.Format("select sum(amount) from records where user_id='%s'",tempID);
	db.QueryAndFetch(cmd, tempCount);
	cPreCountSum.Format("%s", tempCount);
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT3); 
	pEditCtr-> SetWindowText(cPreCountSum);

	// 获取会员备注
	char tempNote[128]={'\0'};
	cmd.Format("select note from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, tempNote);
	cNote.Format("%s", tempNote);
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT5); 
	pEditCtr-> SetWindowText(cNote);
}
