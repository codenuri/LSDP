#define USING_GUI
#include "cppmaster.h" 

// Client 제작자는 서버제작자에게 2개의 파일을 받게 됩니다.
// 1. ICalc.h 
// 2. CalcProxy.dll

#include "ICalc.h"

ICalc* reload_proxy()
{
	void* addr = ec_load_module("CalcProxy.dll");

	typedef ICalc* (*F)(); // 함수 포인터 타입
	
	F f = (F)ec_get_function_address(addr, "Create");

	ICalc* calc = f(); // DLL내부의 함수를 호출해서 Proxy 생성

	return calc;
}


int main()
{
	ICalc* calc = reload_proxy();


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << ", " << n2 << std::endl;

}





