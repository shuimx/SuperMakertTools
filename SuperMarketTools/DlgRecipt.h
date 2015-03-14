#pragma once


// CDlgRecipt 对话框

class CDlgRecipt : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRecipt)

public:
	CDlgRecipt(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgRecipt();

// 对话框数据
	enum { IDD = IDD_DLG_RECIPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedQuery();
private:
	CString cUserId;
};
