#pragma once


// CDlgRecipt �Ի���

class CDlgRecipt : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRecipt)

public:
	CDlgRecipt(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgRecipt();

// �Ի�������
	enum { IDD = IDD_DLG_RECIPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedQuery();
private:
	CString cUserId;
};
