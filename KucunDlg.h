#pragma once


// KucunDlg 对话框

class KucunDlg : public CDialogEx
{
	DECLARE_DYNAMIC(KucunDlg)

public:
	KucunDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~KucunDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnBnClickedButton5();
//	afx_msg void OnBnClickedButton5();
//	afx_msg void OnBnClickedButton3();
//	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedButton2();
	CListCtrl m_List;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
};
