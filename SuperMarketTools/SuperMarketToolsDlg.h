
// SuperMarketToolsDlg.h : ͷ�ļ�
//

#include "DlgRecipt.h"
#include "DlgAddCustom.h"

#pragma once


// CSuperMarketToolsDlg �Ի���
class CSuperMarketToolsDlg : public CDialogEx
{
// ����
public:
	CSuperMarketToolsDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SUPERMARKETTOOLS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAddCustom();
	afx_msg void OnBnClickedBtnRecipt();
};
