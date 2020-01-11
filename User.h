#include"pch.h"
#include "framework.h"
#include <afxcontrolbars.h>
#include <locale>
class User
{
private:
	CString name;
	int num;
public:
	CString Name();
	int Num();
	void Get(CString cs1,CString cs2);
	void Write();
	void Get(CString cs1);
};

