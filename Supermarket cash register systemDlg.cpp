
// Supermarket cash register systemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Supermarket cash register system.h"
#include "Supermarket cash register systemDlg.h"
#include "afxdialogex.h"
#include"Menu.h"	
#include"Resign.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSupermarketcashregistersystemDlg 对话框



CSupermarketcashregistersystemDlg::CSupermarketcashregistersystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SUPERMARKETCASHREGISTERSYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CSupermarketcashregistersystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_static);
	DDX_Control(pDX, IDC_BUTTON9, New_button);
}

BEGIN_MESSAGE_MAP(CSupermarketcashregistersystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON1, &CSupermarketcashregistersystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON9, &CSupermarketcashregistersystemDlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CSupermarketcashregistersystemDlg 消息处理程序

BOOL CSupermarketcashregistersystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Static.CreatePointFont(180, _T("楷体"));
	m_static.SetFont(&m_Static);
	New_button.SetFont(&m_Static);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSupermarketcashregistersystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSupermarketcashregistersystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSupermarketcashregistersystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CSupermarketcashregistersystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	if (pWnd->GetDlgCtrlID()==IDC_STATIC)
	{
		pDC->SetTextColor(RGB(0, 255, 0));
		pDC->SetBkColor(TRANSPARENT);
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CSupermarketcashregistersystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString User, Password;
	GetDlgItemText(IDC_EDIT1, User);
	GetDlgItemText(IDC_EDIT2, Password);
	CStdioFile file;
	file.Open(_T("UserManage.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeRead);
	CString Read[100];
	int i = 1;
	while (file.ReadString(Read[i]))
	{
		i++;
	}
	for (int p = 1; p < i; p++)
	{
		if (p%2==0)
		{
			CString Q = Read[p];
			CString Q1 = Read[p - 1];
			if (Q==Password&&Q1==User)
			{
				MessageBox(_T("登录成功"));
				ShowWindow(SW_HIDE);
				Menu me;
				me.DoModal();
			}
		}
	}
}

void CSupermarketcashregistersystemDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	Resign re;
	re.DoModal();
}
