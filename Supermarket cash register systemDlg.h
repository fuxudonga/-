
// Supermarket cash register systemDlg.h: 头文件
//

#pragma once


// CSupermarketcashregistersystemDlg 对话框
class CSupermarketcashregistersystemDlg : public CDialogEx
{
private:
	CFont m_Static;
// 构造
public:
	CSupermarketcashregistersystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SUPERMARKETCASHREGISTERSYSTEM_DIALOG };
#endif

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
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CButton m_static;
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnClose();
	afx_msg void OnBnClickedButton9();
	CButton New_button;
};
