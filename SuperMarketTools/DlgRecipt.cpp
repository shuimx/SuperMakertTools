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


// CDlgRecipt ��Ϣ�������


void CDlgRecipt::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cCount;
	CEdit* pEditCtr; 
	int len, i;

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

	CSMTDataBase db;
	CString cmd;
	CUtil util;
	CString cTime;

	cTime = util.GetCurrentSysTime();
	cmd.Format("insert into records(user_id,record_time,amount)" 
				"values('%s','%s','%s') ",cUserId, cTime, cCount);
	if(db.Query(cmd)){
		AfxMessageBox(_T("�ɹ���¼�˴�����"),MB_OK);
	}else{
		AfxMessageBox(_T("����ʧ��"),MB_OK);
	}

	CDialogEx::OnOK();
}


void CDlgRecipt::OnBnClickedQuery()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString cPhone;
	CString cName;
	CString cPreCountSum;
	CString cNote;
	int i;

	CEdit* pEditCtr; 
 
	// �ֻ��Ÿ�ʽ���
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT1); 
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
	// ����Ƿ��ǻ�Ա
	CSMTDataBase db;
	CString cmd;
	char num[2]={'\0'};

	cmd.Format("select count(*) from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, num);
	if(num[0]=='0'){
		AfxMessageBox(_T("���ֻ��Ų��ǻ�Ա��������Ա��"),MB_OK);
		return;
	}

	// ��ȡ��Ա����
	char tempName[64]={'\0'};
	cmd.Format("select name from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, tempName);
	cName.Format("%s", tempName);
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT2); 
	pEditCtr-> SetWindowText(cName);

	// ��ȡ��ʷ���ѽ��
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

	// ��ȡ��Ա��ע
	char tempNote[128]={'\0'};
	cmd.Format("select note from customers where phone='%s'",cPhone);
	db.QueryAndFetch(cmd, tempNote);
	cNote.Format("%s", tempNote);
	pEditCtr = (CEdit*) GetDlgItem(IDC_EDIT5); 
	pEditCtr-> SetWindowText(cNote);
}
