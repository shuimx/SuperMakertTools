#pragma once


// CDlgAddCustom 对话框

class CDlgAddCustom : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgAddCustom)

public:
	CDlgAddCustom(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgAddCustom();

// 对话框数据
	enum { IDD = IDD_DLG_ADD_CUSTOM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
