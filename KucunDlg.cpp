// KucunDlg.cpp: 实现文件
//

#include "pch.h"
#include "Supermarket cash register system.h"
#include "KucunDlg.h"
#include "afxdialogex.h"
#include"Cargo.h"

// KucunDlg 对话框

IMPLEMENT_DYNAMIC(KucunDlg, CDialogEx)

KucunDlg::KucunDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

KucunDlg::~KucunDlg()
{
}

void KucunDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
}


BEGIN_MESSAGE_MAP(KucunDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &KucunDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &KucunDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &KucunDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &KucunDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// KucunDlg 消息处理程序


void KucunDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cs1, cs2, cs3, cs4;
	GetDlgItemText(IDC_EDIT_HUOHAO, cs1);
	GetDlgItemText(IDC_EDIT_NAME, cs2);
	GetDlgItemText(IDC_EDIT_JINJIA, cs3);
	GetDlgItemText(IDC_EDIT_SHOUJIA, cs4);
	Cargo co;
	co.Get(cs1, cs2, cs3, cs4);
	int i = m_List.GetItemCount();
	m_List.InsertItem(i, cs1);
	m_List.SetItemText(i, 0, cs1);
	m_List.SetItemText(i, 1, cs2);
	m_List.SetItemText(i, 2, cs3);
	m_List.SetItemText(i, 3, cs4);
	co.Write();
	MessageBox(_T("录入成功"));
}


BOOL KucunDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_List.InsertColumn(0, _T("货号"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(1, _T("名称"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(3, _T("进货价"), LVCFMT_LEFT, 100);
	m_List.InsertColumn(4, _T("销售价"), LVCFMT_LEFT, 100);
	setlocale(LC_CTYPE, ("chs"));
	CString cs1, cs2, cs3, cs4;
	CStdioFile huohao, name1, jinhuojia, xiaoshoujia;
	huohao.Open(_T("huohao.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	name1.Open(_T("name1.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	jinhuojia.Open(_T("jinhuojia.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	xiaoshoujia.Open(_T("xiaoshoujia.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	while (huohao.ReadString(cs1) && name1.ReadString(cs2) && jinhuojia.ReadString(cs3) && xiaoshoujia.ReadString(cs4))
	{
		int i = m_List.GetItemCount();
		m_List.InsertItem(i, cs1);
		m_List.SetItemText(i, 0, cs1);
		m_List.SetItemText(i, 1, cs2);
		m_List.SetItemText(i, 2, cs3);
		m_List.SetItemText(i, 3, cs4);
	}
	huohao.Close();
	name1.Close();
	jinhuojia.Close();
	xiaoshoujia.Close();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void KucunDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION ps;
	int nIndex;
	ps = m_List.GetFirstSelectedItemPosition();
	nIndex = m_List.GetNextSelectedItem(ps);//nIndex为选中的列表项Item值
	m_List.DeleteItem(nIndex);
}


void KucunDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile huohao, name1, jinhuojia, xiaoshoujia;
	huohao.Open(_T("huohao.txt"), CFile::modeCreate);
	name1.Open(_T("name1.txt"), CFile::modeCreate);
	jinhuojia.Open(_T("jinhuojia.txt"), CFile::modeCreate);
	xiaoshoujia.Open(_T("xiaoshoujia.txt"), CFile::modeCreate);
	huohao.Close();
	name1.Close();
	jinhuojia.Close();
	xiaoshoujia.Close();
	int i = m_List.GetItemCount();
	CString cs1, cs2, cs3, cs4;
	Cargo ca;
	for (int j = 0; j < i; j++)
	{
		cs1 = m_List.GetItemText(j, 0);
		cs2 = m_List.GetItemText(j, 1);
		cs3 = m_List.GetItemText(j, 2);
		cs4 = m_List.GetItemText(j, 3);
		ca.Get(cs1, cs2, cs3, cs4);
		ca.Write();
	}
	MessageBox(_T("保存成功"));
}


void KucunDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos;
	pos = m_List.GetFirstSelectedItemPosition();
	int Index = m_List.GetNextSelectedItem(pos);
	CString cs1, cs2, cs3, cs4;
	GetDlgItemText(IDC_EDIT_HUOHAO, cs1);
	GetDlgItemText(IDC_EDIT_NAME, cs2);
	GetDlgItemText(IDC_EDIT_JINJIA, cs3);
	GetDlgItemText(IDC_EDIT_SHOUJIA, cs4);
	m_List.SetItemText(Index, 0, cs1);
	m_List.SetItemText(Index, 1, cs2);
	m_List.SetItemText(Index, 2, cs3);
	m_List.SetItemText(Index, 3, cs4);
}
