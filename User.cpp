#include"User.h"
#include"pch.h"
CString User::Name()
{
	return name;
}

int User::Num()
{
	return num;
}

void User::Get(CString cs1,CString cs2)
{
	name = cs1;
	num = _ttoi(cs2);
}

void User::Write()
{
	CStdioFile file1,file2;
	file1.Open(_T("name.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	file2.Open(_T("num.txt"), CFile::modeCreate | CFile::modeNoTruncate | CFile::modeReadWrite);
	setlocale(LC_CTYPE, ("chs"));
	CString cs2;
	cs2.Format(_T("%d"), num);
	file1.SeekToEnd();
	file1.WriteString(name+'\n');
	file2.SeekToEnd();
	file2.WriteString(cs2 + '\n');
	file2.Close();
	file1.Close();
}

void User::Get(CString cs1)
{
	name = cs1;
}