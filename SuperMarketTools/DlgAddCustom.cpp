// DlgAddCustom.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SuperMarketTools.h"
#include "DlgAddCustom.h"
#include "afxdialogex.h"
#include "Util.h"


// CDlgAddCustom �Ի���

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


// CDlgAddCustom ��Ϣ�������


void CDlgAddCustom::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cName;
	CString cPhone;
	CString cCount;
	CString cNote;
	int i,len;
	CString cmd;


	CEdit* pEditCtr; 
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT1); 
	pEditCtr-> GetWindowText(cName);
 
	// �ֻ��ż��
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT2); 
	pEditCtr-> GetWindowText(cPhone);
	if(cPhone.GetLength() != 11){
		AfxMessageBox(_T("�ֻ�����������ֻ���ҪΪ11λ���֡�"),MB_OKCANCEL);
		return;
	}
	for(i = 0; i < 11; i++){
		if((cPhone.GetAt(i) > '9')|| (cPhone.GetAt(i) < '0')){
			AfxMessageBox(_T("�ֻ�����������ֻ���ҪΪ11λ���֡�"),MB_OKCANCEL);
			return;
		}
	}
 
	// �������ѽ����
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT4); 
	pEditCtr-> GetWindowText(cCount);
	len = cCount.GetLength();
	for(i = 0; i < len; i++){
		if((cCount.GetAt(i) > '9')|| (cCount.GetAt(i) < '0') && (cCount.GetAt(i)!='.')){
			AfxMessageBox(_T("���ѽ��������󡣸�ʽΪ 12 ���� 1.5��"),MB_OKCANCEL);
			return;
		}
	}

	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT3); 
	pEditCtr-> GetWindowText(cNote);

	cmd.Format("insert into customers(name,sex,phone,address,note)" 
		      "values('%s','','%s','','%s')",cName, cPhone, cNote);
	CSMTDataBase db;
	if(db.Query(cmd)){
		AfxMessageBox(_T("�ɹ�����һλ��Ա"),MB_OK);
	}else{
		AfxMessageBox(_T("����ʧ��"),MB_OK);
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
			AfxMessageBox(_T("�ɹ���¼�˴�����"),MB_OK);
		}else{
			AfxMessageBox(_T("����ʧ��"),MB_OK);
		}
	}
	CDialogEx::OnOK();
}
