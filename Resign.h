#pragma once


// Resign 对话框

class Resign : public CDialogEx
{
	DECLARE_DYNAMIC(Resign)

public:
	Resign(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Resign();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
