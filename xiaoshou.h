#include"pch.h"	
// xiaoshou 对话框

class xiaoshou : public CDialogEx
{
private:
	CFont font;
	DECLARE_DYNAMIC(xiaoshou)

public:
	xiaoshou(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~xiaoshou();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
//	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	virtual BOOL OnInitDialog();
	CButton m_Cbutton2;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	CListCtrl m_List_HUOHAO;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
};
