#include"pch.h"
class MoneySta
{
private:
	double *Money;
	int i;
public:
	MoneySta(int i);
	~MoneySta();
	void Get(CString*p);
	CString Add();
};

