#define USING_GUI
#include "cppmaster.h" 

// Client �����ڴ� ���������ڿ��� 2���� ������ �ް� �˴ϴ�.
// 1. ICalc.h 
// 2. CalcProxy.dll

#include "ICalc.h"

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc* (*F)(); // �Լ� ������ Ÿ��
	
	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* calc = f(); // DLL������ �Լ��� ȣ���ؼ� Proxy ����

	return calc;
}


int main()
{
	ICalc* calc = reload_proxy();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





