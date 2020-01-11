// xiaoshou.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "xiaoshou.h"
#include "afxdialogex.h"


// xiaoshou 对话框

IMPLEMENT_DYNAMIC(xiaoshou, CDialogEx)

xiaoshou::xiaoshou(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}


xiaoshou::~xiaoshou()
{
}


void xiaoshou::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_BUTTON2, m_Cbutton2);
	DDX_Control(pDX, IDC_LIST2, m_List_HUOHAO);
}


BEGIN_MESSAGE_MAP(xiaoshou, CDialogEx)
	//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &xiaoshou::OnLvnItemchangedList1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &xiaoshou::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &xiaoshou::OnBnClickedButton1)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// xiaoshou 消息处理程序

BOOL xiaoshou::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	font.CreatePointFont(200, _T("宋体"));
	m_Cbutton2.SetFont(&font);

	m_List.InsertColumn(0, _T("时间"), LVCFMT_LEFT, 135);
	m_List.InsertColumn(1, _T("货号"), LVCFMT_LEFT, 75);
	m_List.InsertColumn(3, _T("名称"), LVCFMT_LEFT, 75);
	m_List.InsertColumn(4, _T("数量"), LVCFMT_LEFT, 75);
	m_List.InsertColumn(5, _T("总金额"), LVCFMT_LEFT, 75);

	SetTimer(1, 500, NULL);

	m_List_HUOHAO.InsertColumn(0, _T("名称"), LVCFMT_LEFT, 75);
	m_List_HUOHAO.InsertColumn(1, _T("价格"), LVCFMT_LEFT, 75);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void xiaoshou::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SYSTEMTIME st;
	GetLocalTime(&st);
	CString cs1;
	cs1.Format(_T("%u/%u/%u %u:%u:%u\n"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	SetDlgItemText(IDC_EDIT_TIME, cs1);
	CDialogEx::OnTimer(nIDEvent);
}


void xiaoshou::OnBnClickedButton2()
{
	CString Time;
	GetDlgItemText(IDC_EDIT_TIME, Time);
	int i = m_List.GetItemCount();
	m_List.InsertItem(i, Time);
	m_List.SetItemText(i, 0, Time);
	// TODO: 在此添加控件通知处理程序代码
	CString huohao1, name1, shoujia1;
	setlocale(LC_CTYPE, ("chs"));
	name1 = m_List_HUOHAO.GetItemText(0, 0);
	shoujia1 = m_List_HUOHAO.GetItemText(0, 1);
	GetDlgItemText(IDC_EDIT_HUOHAO_2, huohao1);
	double dd = _ttof(shoujia1);
	CString cs1;
	GetDlgItemText(IDC_EDIT_NUM_3, cs1);
	int p = _ttoi(cs1);				//数量
	dd = dd * p;
	CString cs3;
	cs3.Format(_T("%f"), dd);
	SetDlgItemText(IDC_EDIT_MONEY_2, cs3);
	m_List.SetItemText(i, 1, huohao1);
	m_List.SetItemText(i, 2, name1);
	m_List.SetItemText(i, 3, cs1);
	m_List.SetItemText(i, 4, cs3);
}


void xiaoshou::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString huowu, jiage, name1;
	CStdioFile huohao, shoujia, name;
	setlocale(LC_CTYPE, ("chs"));
	huohao.Open(_T("huohao.txt"), CFile::modeRead);
	shoujia.Open(_T("xiaoshoujia.txt"), CFile::modeRead);
	name.Open(_T("name1.txt"), CFile::modeRead);
	CString cs1;
	GetDlgItemText(IDC_EDIT_HUOHAO_2, cs1);
	while (huohao.ReadString(huowu) && shoujia.ReadString(jiage) && name.ReadString(name1))
	{
		if (huowu == cs1)
		{
			m_List_HUOHAO.InsertItem(0, name1);
			m_List_HUOHAO.SetItemText(0, 0, name1);
			m_List_HUOHAO.SetItemText(0, 1, jiage);
			break;
		}
	}
	huohao.Close();
	shoujia.Close();
	name.Close();
}


void xiaoshou::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CStdioFile file;
	int i = m_List.GetItemCount();
	CString Time;
	Time = m_List.GetItemText(0, 0);
	file.Open(_T("file.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	CString cs[100][5];
	for (int j = 0; j < i; j++)
	{
		for (int p = 0; p < 5; p++)
		{
			cs[j][p] = m_List.GetItemText(j, p);
			file.SeekToEnd();
			setlocale(LC_CTYPE, ("chs"));
			if (p == 0)
			{
				file.WriteString(cs[j][p]);
			}
			else
			{
				file.WriteString(cs[j][p] + "     ");
			}
			CString cs;
		}
		file.WriteString(_T("\n"));
	}
	file.Close();
	CDialogEx::OnClose();
}
