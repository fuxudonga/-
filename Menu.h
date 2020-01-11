#pragma once


// Menu 对话框

class Menu : public CDialogEx
{
	DECLARE_DYNAMIC(Menu)

private:
	CFont font;
public:
	Menu(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Menu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
//	CTabCtrl m_Table;
	virtual BOOL OnInitDialog();
//	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonRegister();
//	CString name;
//	int num;
	afx_msg void OnBnClickedButtonOk();
	afx_msg void OnBnClickedButton2();
//	CButton m_Button;
//	CFont m_Button;
	CButton m_Button;
	afx_msg void OnBnClickedButton1();
	CButton m_ButtonOne;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CButton m_CBUTTON;
	CButton m_Bu;
	afx_msg void OnBnClickedButton8();
};
