#include "pch.h"
#include "Cargo.h"

void Cargo::Get(CString num, CString name, CString jinjia, CString shoujia)
{
	this->num = _ttoi(num);
	this->name = name;
	this->jinhuo = _ttof(jinjia);
	this->shoujia = _ttof(shoujia);
}

void Cargo::Write()
{
	CStdioFile huohao, name1, jinhuojia, xiaoshoujia;
	huohao.Open(_T("huohao.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	name1.Open(_T("name1.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	jinhuojia.Open(_T("jinhuojia.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	xiaoshoujia.Open(_T("xiaoshoujia.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	CString cs1;
	setlocale(LC_CTYPE, ("chs"));
	cs1.Format(_T("%d"), num);
	huohao.SeekToEnd();
	huohao.WriteString(cs1+'\n');
	name1.SeekToEnd();
	name1.WriteString(name+'\n');
	cs1.Format(_T("%f"), jinhuo);
	jinhuojia.SeekToEnd();
	jinhuojia.WriteString(cs1+ '\n');
	cs1.Format(_T("%f"), shoujia);
	xiaoshoujia.SeekToEnd();
	xiaoshoujia.WriteString(cs1+'\n');
	huohao.Close();
	name1.Close();
	jinhuojia.Close();
	xiaoshoujia.Close();
}