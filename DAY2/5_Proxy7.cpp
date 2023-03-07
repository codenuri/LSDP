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
		
	p1->AddRef(); // ��Ģ 1. proxy�� ������ ������� ����

	ICalc* p2 = p1;
	p2->AddRef(); // ��Ģ 2. Proxy �����͸� �����ϸ� ������� ����

	// ��Ģ 3. ���̻� �ʿ������ ������� ����
	p2->Release();

	std::cout << "------------" << std::endl;
	p1->Release();
	std::cout << "------------" << std::endl;




}





