#include "pch.h"
#include "MoneySta.h"

MoneySta::MoneySta(int i)
{
	this->i = i;
	Money = new double[this->i];
}


void MoneySta::Get(CString* New)
{
	for (int p = 0; p < i; p++)
	{
		Money[p] = _ttof(New[p]);
	}
}

MoneySta::~MoneySta()
{
	delete[]Money;
}

CString MoneySta::Add()
{
	double o = 0;
	for (int p = 0; p < i; p++)
	{
		o = o + Money[p];
	}
	CString cs1;
	cs1.Format(_T("%f"), o);
	return cs1;
}