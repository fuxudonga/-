// Resign.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "Resign.h"
#include "afxdialogex.h"


// Resign 对话框

IMPLEMENT_DYNAMIC(Resign, CDialogEx)

Resign::Resign(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

Resign::~Resign()
{
}

void Resign::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Resign, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Resign::OnBnClickedButton1)
END_MESSAGE_MAP()


// Resign 消息处理程序


void Resign::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString Password, User;
	GetDlgItemText(IDC_EDIT_PASSWORD, Password);
	GetDlgItemText(IDC_EDIT_User, User);
	CStdioFile file;
	file.Open(_T("UserManage.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite);
	file.WriteString(User+'\n'+Password+'\n');
	file.Close();
}
