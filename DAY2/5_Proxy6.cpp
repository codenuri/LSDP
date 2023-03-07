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
	ICalc* calc = reload_proxy();
					// 이 순간 DLL 내부에서 "new Calc"하게됩니다.
					// 사용후에는 반드시 "delete" 해야 합니다.
	calc->

//	delete calc; // ?? 좋은 코드인가요 ?
				 // 동적모듈 내부에서 할당한 자원은
				 // 동적모듈 내부에서 해지 하는 것이 가장 좋은 코드입니다





}





