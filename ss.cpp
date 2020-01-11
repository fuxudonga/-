// ss.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "ss.h"
#include "afxdialogex.h"


// ss 对话框

IMPLEMENT_DYNAMIC(ss, CDialogEx)

ss::ss(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FORMVIEW, pParent)
{

}

ss::~ss()
{
}

void ss::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ss, CDialogEx)
END_MESSAGE_MAP()


// ss 消息处理程序
