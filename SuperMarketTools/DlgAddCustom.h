#pragma once


// CDlgAddCustom �Ի���

class CDlgAddCustom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddCustom)

public:
	CDlgAddCustom(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgAddCustom();

// �Ի�������
	enum { IDD = IDD_DLG_ADD_CUSTOM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
