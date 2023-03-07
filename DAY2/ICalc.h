// ICalc.h
#pragma once

// 모든 종류의 Proxy 는 결국 참조 계수 함수가 필요 하다.
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