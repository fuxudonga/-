// TongJi.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "TongJi.h"
#include "afxdialogex.h"
#include"MoneySta.h"

// TongJi 对话框

IMPLEMENT_DYNAMIC(TongJi, CDialogEx)

TongJi::TongJi(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

TongJi::~TongJi()
{
}

void TongJi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TongJi, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TongJi::OnBnClickedButton1)
	//	ON_WM_TIMER()
END_MESSAGE_MAP()


// TongJi 消息处理程序


void TongJi::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file;
	file.Open(_T("file.txt"), CFile::modeRead);
	CString Money[1000], pp;

	int i = 1, p = 0;
	setlocale(LC_CTYPE, ("chs"));
	SYSTEMTIME time;
	GetLocalTime(&time);
	CString Time, Time_T;
	Time.Format(_T("%u/%u/%u"), time.wYear, time.wMonth, time.wDay);
	while (file.ReadString(pp))
	{
		if ((i % 2) == 0)
		{
			Money[p] = pp;
			Money[p] = Money[p].Mid(19, 70);
			Money[p].Remove(' ');
			p++;
		}
		i++;
	}
	file.Close();
	file.Open(_T("file.txt"), CFile::modeRead);
	int o = 0, q = 0;
	CString New[1000];
	while (file.ReadString(pp))
	{
		pp = pp.Left(9);
		pp.Remove(' ');
		if (Time == pp)
		{
			New[o] = Money[o];
			o++;
		}
	}
	MoneySta money(o);
	money.Get(New);
	pp = money.Add();
	SetDlgItemText(IDC_EDIT1, pp);
}
