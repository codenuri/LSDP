#define USING_GUI
#include "cppmaster.h" 


#include "ICalc.h"

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc* (*F)();

	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* calc = f();

	return calc;
}


int main()
{
	ICalc* p1 = reload_proxy();
		
	p1->AddRef(); // 규칙 1. proxy를 얻으면 참조계수 증가

	ICalc* p2 = p1;
	p2->AddRef(); // 규칙 2. Proxy 포인터를 복사하면 참조계수 증가

	// 규칙 3. 더이상 필요없으면 참조계수 감소
	p2->Release();

	std::cout << "------------" << std::endl;
	p1->Release();
	std::cout << "------------" << std::endl;




}





