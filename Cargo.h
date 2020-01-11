#include"pch.h"
class Cargo
{
private:
	int num;		//货号
	CString name;	//名称
	double jinhuo;	//进价
	double shoujia;	//售价
public:
	void Write();
	void Get(CString num, CString name, CString jinjia, CString shoujia);
};

