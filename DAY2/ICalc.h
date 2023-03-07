// ICalc.h
#pragma once

// ��� ������ Proxy �� �ᱹ ���� ��� �Լ��� �ʿ� �ϴ�.
struct IRef
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRef() {}
};

struct ICalc : public IRef
{
	virtual int Add(int, int) = 0;
	virtual int Sub(int, int) = 0;
	virtual ~ICalc() {}
};

// cl calcproxy.cpp /LD