// Menu.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "Menu.h"
#include "afxdialogex.h"
#include"UserDlg.h"
#include"KucunDlg.h"
#include"xiaoshou.h"
#include"TongJi.h"
using namespace std;
// Menu 对话框

IMPLEMENT_DYNAMIC(Menu, CDialogEx)

Menu::Menu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

Menu::~Menu()
{
}

void Menu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_BUTTON1, m_Button);
	//  DDX_Control(pDX, IDC_BUTTON1, m_Button);
	DDX_Control(pDX, IDC_BUTTON1, m_Button);
	DDX_Control(pDX, IDC_BUTTON6, m_ButtonOne);
	DDX_Control(pDX, IDC_BUTTON7, m_CBUTTON);
	DDX_Control(pDX, IDC_BUTTON8, m_Bu);
}


BEGIN_MESSAGE_MAP(Menu, CDialogEx)
	ON_WM_CLOSE()
	//	ON_BN_CLICKED(IDC_BUTTON1, &Menu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_REGISTER, &Menu::OnBnClickedButtonRegister)
	ON_BN_CLICKED(IDC_BUTTON_OK, &Menu::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDC_BUTTON2, &Menu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Menu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON6, &Menu::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &Menu::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &Menu::OnBnClickedButton8)
END_MESSAGE_MAP()


// Menu 消息处理程序


void Menu::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CDialog* pdlg = (CDialog*)AfxGetMainWnd();
	pdlg->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL Menu::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	font.CreatePointFont(180, _T("楷体"));
	m_Button.SetFont(&font);
	m_ButtonOne.SetFont(&font);
	m_CBUTTON.SetFont(&font);
	m_Bu.SetFont(&font);
	// TODO:  在此添加额外的初始化
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Menu::OnBnClickedButtonRegister()
{
	// TODO: 在此添加控件通知处理程序代码
	User us;
	CString cs1, cs2;
	GetDlgItemText(IDC_EDIT_NAME, cs1);
	GetDlgItemText(IDC_EDIT_PASSWORD, cs2);
	us.Get(cs1, cs2);
	us.Write();
}


void Menu::OnBnClickedButtonOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file1, file2;
	file1.Open(_T("name.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	file2.Open(_T("num.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	setlocale(LC_CTYPE, ("chs"));
	CString cs1, cs3, cs2, cs4;
	GetDlgItemText(IDC_EDIT_NAME, cs1);
	GetDlgItemText(IDC_EDIT_PASSWORD, cs2);
	while (file1.ReadString(cs3) && file2.ReadString(cs4))
	{
		if (cs3 == cs1 && cs4 == cs2)
		{
			MessageBox(_T("有这个人"));
		}
	}
}


void Menu::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UserDlg user;
	user.DoModal();
}


void Menu::OnBnClickedButton1()
{
	KucunDlg kucun;
	kucun.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void Menu::OnBnClickedButton6()
{
	xiaoshou xs;
	xs.DoModal();
	// TODO: 在此添加控件通知处理程序代码
}


void Menu::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	TongJi tong;
	tong.DoModal();	
}


void Menu::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CopyFile(_T("./file.txt"), _T("D:\\销售记录.txt"),TRUE);
	MessageBox(_T("导出成功,文件位置为D://销售记录.txt"));
}
