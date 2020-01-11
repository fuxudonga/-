// UserDlg.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "UserDlg.h"
#include "afxdialogex.h"

// UserDlg 对话框

IMPLEMENT_DYNAMIC(UserDlg, CDialogEx)

UserDlg::UserDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

UserDlg::~UserDlg()
{
}

void UserDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_LIST2, m_List);
}


BEGIN_MESSAGE_MAP(UserDlg, CDialogEx)
END_MESSAGE_MAP()


// UserDlg 消息处理程序


BOOL UserDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CStdioFile file1, file2;
	file1.Open(_T("name.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	file2.Open(_T("num.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	setlocale(LC_CTYPE, ("chs"));
	CString cs1, cs2;
	m_List.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 150);
	m_List.InsertColumn(1, _T("卡号"), LVCFMT_LEFT, 150);
	
	while (file1.ReadString(cs1) && file2.ReadString(cs2))
	{
		int i = m_List.GetItemCount();
		m_List.InsertItem(i, cs1);
		m_List.SetItemText(i, 0, cs1);
		m_List.SetItemText(i, 1, cs2);
	}
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
