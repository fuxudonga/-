#pragma once


// ss 对话框

class ss : public CDialogEx
{
	DECLARE_DYNAMIC(ss)

public:
	ss(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ss();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
