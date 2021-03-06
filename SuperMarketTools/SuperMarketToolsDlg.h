
// SuperMarketToolsDlg.h : 头文件
//

#include "DlgRecipt.h"
#include "DlgAddCustom.h"

#pragma once


// CSuperMarketToolsDlg 对话框
class CSuperMarketToolsDlg : public CDialogEx
{
// 构造
public:
	CSuperMarketToolsDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SUPERMARKETTOOLS_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnAddCustom();
	afx_msg void OnBnClickedBtnRecipt();
};
